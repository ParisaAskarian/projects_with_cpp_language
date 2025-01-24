This is a calculator that calculate equations 
with any grade.

import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import LoginPage from './components/LoginPage';
import UserPage from './components/UserPage';
import LibrarianPage from './components/LibrarianPage';
import SearchAIPage from './components/SearchAIPage';

const App = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<LoginPage />} />
        <Route path="/user" element={<UserPage />} />
        <Route path="/librarian" element={<LibrarianPage />} />
        <Route path="/search-ai" element={<SearchAIPage />} />
        <Route path="*" element={<h2>Page Not Found</h2>} />
      </Routes>
    </Router>
  );
};

export default App;
