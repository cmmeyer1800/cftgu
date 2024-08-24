import { Outlet } from "react-router-dom";

import Nav from "./Navbar.js"
import Footer from "./Footer.js";

const Layout = () => {
  return (
    <>
        <Nav />
        <Outlet />
        <Footer/>
    </>
  )
};

export default Layout;