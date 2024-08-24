import { createContext, useState, useEffect } from 'react';
import { useCookies } from 'react-cookie';

import { FaSun, FaMoon } from "react-icons/fa6";

const ThemeContext = createContext({
    theme: 'dark',
    toggleTheme: () => {}
});

const ThemeManager = ({ children }) => {
    const [theme, setTheme] = useState('dark');
    const [cookies, setCookie,] = useCookies(['cftgu-theme']);

    const toggleTheme = () => {
        var root = document.getElementsByTagName('html')[0];
        const updatedTheme = theme === 'dark' ? 'light' : 'dark';

        setCookie('cftgu-theme', updatedTheme, { path: '/' });
        root.setAttribute('class', `theme-${updatedTheme}`);
        setTheme(updatedTheme);
    }

    const initTheme = () => {
        if (cookies['cftgu-theme'] !== undefined) {
            var root = document.getElementsByTagName('html')[0];
            root.setAttribute('class', `theme-${cookies['cftgu-theme']}`);
            setTheme(cookies['cftgu-theme']);
        }
    }

    useEffect(() => {
        initTheme();
    });

    return (
        <ThemeContext.Provider value={{theme, toggleTheme}}>
            {children}
        </ThemeContext.Provider>
    );
}

const ThemeUpdaterButton = () => {
    return (
        <ThemeContext.Consumer>
            {({ theme, toggleTheme }) => (
                <button className="icon-text" onClick={toggleTheme}>
                    <span className="icon">
                        {theme === 'dark' ? <FaSun /> : <FaMoon />}
                    </span>
                    <span>
                        {theme === 'dark' ? 'Light' : 'Dark'}
                    </span>
                </button>
            )}
        </ThemeContext.Consumer>
    );
}

export {ThemeContext, ThemeManager, ThemeUpdaterButton};