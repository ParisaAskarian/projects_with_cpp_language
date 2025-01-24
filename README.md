This is a calculator that calculate equations 
with any grade.

import React, { useState } from 'react';

const LibrarianPage = () => {
  const [books, setBooks] = useState([
    { id: 1, title: 'The Great Gatsby', author: 'F. Scott Fitzgerald' },
    { id: 2, title: '1984', author: 'George Orwell' },
  ]);
  const [newBook, setNewBook] = useState({ title: '', author: '' });

  const addBook = () => {
    if (newBook.title && newBook.author) {
      setBooks([...books, { id: books.length + 1, ...newBook }]);
      setNewBook({ title: '', author: '' });
    }
  };

  const removeBook = (id) => {
    setBooks(books.filter((book) => book.id !== id));
  };

  return (
    <div>
      <h2>Librarian Dashboard</h2>
      <h3>Add a New Book</h3>
      <input
        type="text"
        placeholder="Title"
        value={newBook.title}
        onChange={(e) => setNewBook({ ...newBook, title: e.target.value })}
      />
      <input
        type="text"
        placeholder="Author"
        value={newBook.author}
        onChange={(e) => setNewBook({ ...newBook, author: e.target.value })}
      />
      <button onClick={addBook}>Add Book</button>
      <h3>Books List</h3>
      <ul>
        {books.map((book) => (
          <li key={book.id}>
            {book.title} by {book.author}{' '}
            <button onClick={() => removeBook(book.id)}>Remove</button>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default LibrarianPage;
