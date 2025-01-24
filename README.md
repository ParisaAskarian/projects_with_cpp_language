This is a calculator that calculate equations 
with any grade.

import React, { useState } from 'react';
import axios from 'axios';

const SearchAIPage = () => {
  const [query, setQuery] = useState('');
  const [response, setResponse] = useState('');

  const handleChat = async () => {
    const res = await axios.post('https://api.openai.com/v1/completions', {
      prompt: query,
      model: 'text-davinci-003',
      max_tokens: 100,
    }, {
      headers: {
        Authorization: `Bearer YOUR_OPENAI_API_KEY`,
      },
    });
    setResponse(res.data.choices[0].text);
  };

  return (
    <div>
      <h2>Chat with AI</h2>
      <textarea
        placeholder="Ask about books..."
        onChange={(e) => setQuery(e.target.value)}
      />
      <button onClick={handleChat}>Send</button>
      <p>{response}</p>
    </div>
  );
};

export default SearchAIPage;
