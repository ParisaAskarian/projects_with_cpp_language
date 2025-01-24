This is a calculator that calculate equations 
with any grade.

import React, { useState } from 'react';

const LibrarianPage = () => {
  const [books, setBooks] = useState(['Book 1', 'Book 2']);
  const [newBook, setNewBook] = useState('');

  const handleAddBook = () => {
    setBooks([...books, newBook]);
    setNewBook('');
  };

  const handleRemoveBook = (book) => {
    setBooks(books.filter((b) => b !== book));
  };

  return (
    <div>
      <h2>Librarian Dashboard</h2>
      <h3>Add Book</h3>
      <input
        type="text"
        value={newBook}
        onChange={(e) => setNewBook(e.target.value)}
        placeholder="Enter book name"
      />
      <button onClick={handleAddBook}>Add Book</button>
      <h3>Book List</h3>
      <ul>
        {books.map((book) => (
          <li key={book}>
            {book} <button onClick={() => handleRemoveBook(book)}>Remove</button>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default LibrarianPage;
