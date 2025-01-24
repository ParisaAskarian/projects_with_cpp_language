This is a calculator that calculate equations 
with any grade.

import React, { useState } from 'react';

const UserPage = () => {
  const [searchTerm, setSearchTerm] = useState('');
  const books = [
    { id: 1, title: 'The Great Gatsby', author: 'F. Scott Fitzgerald' },
    { id: 2, title: '1984', author: 'George Orwell' },
    { id: 3, title: 'To Kill a Mockingbird', author: 'Harper Lee' },
  ];

  const user = {
    name: 'John Doe',
    email: 'john@example.com',
    borrowedBooks: ['1984'],
    reservedBooks: ['The Great Gatsby'],
    fines: 10,
  };

  const filteredBooks = books.filter((book) =>
    book.title.toLowerCase().includes(searchTerm.toLowerCase())
  );

  return (
    <div>
      <h2>User Dashboard</h2>
      <p>Name: {user.name}</p>
      <p>Email: {user.email}</p>
      <p>Fines: ${user.fines}</p>
      <h3>Borrowed Books</h3>
      <ul>
        {user.borrowedBooks.map((book) => (
          <li key={book}>{book}</li>
        ))}
      </ul>
      <h3>Reserved Books</h3>
      <ul>
        {user.reservedBooks.map((book) => (
          <li key={book}>{book}</li>
        ))}
      </ul>
      <h3>Search for a Book</h3>
      <input
        type="text"
        placeholder="Search by title"
        value={searchTerm}
        onChange={(e) => setSearchTerm(e.target.value)}
      />
      <ul>
        {filteredBooks.map((book) => (
          <li key={book.id}>{book.title} by {book.author}</li>
        ))}
      </ul>
    </div>
  );
};

export default UserPage;
