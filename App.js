import React from 'react';
import DataFetching from './DataFetching';

const App=()=>{
  return(
    <div>
      <h1>Data Fetching</h1>
      <DataFetching/>
    </div>
  );
};

export default App;



import React from 'react';
import './App.css';
import Form from './Form';

const App=()=> {
  return (
    <div className="App">
      <p>React Form Validation</p>
      <Form/>
    </div>
  );
};

export default App;




import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Header from './Header';
import Footer from './Footer';
import Home from './Home';
import AboutUs from './AboutUs';
import ContactUs from './Contact';

const App = () => {
  return (
    <Router>
      <Header />
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/AboutUs" element={<AboutUs />} />
        <Route path="/Contact" element={<ContactUs />} />
      </Routes>
      <Footer />
    </Router>
  );
};

export default App;


