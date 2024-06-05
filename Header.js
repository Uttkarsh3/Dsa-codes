// src/Header.js
import React from 'react';
import { Link } from 'react-router-dom';

const Header = () => {
  return (
    <header>
      <nav>
        <ul>
          <li><Link to="/">Home</Link></li>
          <li><Link to="/AboutUs">About Us</Link></li>
          <li><Link to="/Contact">Contact Us</Link></li>
        </ul>
      </nav>
    </header>
  );
};

export default Header;
