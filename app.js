const express = require('express');
const fs = require('fs');
const app = express();
const port = 8080;

app.get('/', (req, res) => {
  fs.readFile('./sample.txt', 'utf-8', (err, data) => {
    if (err) {
      return res.status(500).send(err);
    }

    res.send(`
      <html>
        <head>
          <title>My Node.js App</title>
        </head>
        <body>
          <h1>Contents of sample.txt</h1>
          <pre>${data}</pre>
        </body>
      </html>
    `);
  });
});

app.listen(port, () => {
  console.log(`App listening at http://localhost:${port}`);
});
