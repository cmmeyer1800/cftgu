import { useState } from "react";
import { FaGithub } from "react-icons/fa";

import { ThemeUpdaterButton } from "./context/ThemeContext";

const Nav = () => {
    // const location = useLocation();
    const [burgOpen, setBurgOpen] = useState(false);
    const [titleText, setTitleText] = useState("CFTGU");

    const slideTitleOpen = () => {
        setTitleText("Computing From The Ground Up");
    };

    const slideTitleClose = () => {
        setTitleText("CFTGU")
    };

    return (
        <nav className="navbar _nav" role="navigation" aria-label="main navigation">
            <div className="navbar-brand">
                <a className="navbar-item has-text-weight-bold" href="/"
                   onMouseEnter={slideTitleOpen} onMouseLeave={slideTitleClose}>
                    {titleText}
                </a>

                <a role="button" className={`navbar-burger ${burgOpen ? 'is-active': ''}`} href="/#more"
                   aria-label="menu" onClick={(e) => {setBurgOpen(!burgOpen); e.preventDefault()}}
                aria-expanded="false" data-target="navbarBasicExample">
                    <span aria-hidden="true"></span>
                    <span aria-hidden="true"></span>
                    <span aria-hidden="true"></span>
                    <span aria-hidden="true"></span>
                </a>
            </div>

            <div id="navbarBasicExample" className={`navbar-menu ${burgOpen ? 'is-active': ''}`}>
                <div className="navbar-start">

                    <a className="navbar-item" href="https://github.com/cmmeyer1800/cftgu">
                        <span>Github</span>
                        <span className="icon-text">
                            <span className="icon">
                                <FaGithub/>
                            </span>
                        </span>
                    </a>

                    {/* <div className="navbar-item has-dropdown is-hoverable">
                        <a className="navbar-link">
                        More [WIP]
                        </a>

                        <div className="navbar-dropdown">
                            <a className="navbar-item">
                                About [WIP]
                            </a>
                            <a className="navbar-item">
                                Contact [WIP]
                            </a>
                            <hr className="navbar-divider"></hr>
                            <a className="navbar-item">
                                Report an issue [WIP]
                            </a>
                        </div>
                    </div> */}
                </div>

                <div className="navbar-end">
                    <div className="navbar-item">
                        <ThemeUpdaterButton/>
                    </div>
                </div>
            </div>
        </nav>
    )
}

export default Nav;