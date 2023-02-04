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
          <pre>${data}</pre>
          <button id="myButton">Press Me</button>
          <script>
          const button = document.getElementById("myButton");
          button.addEventListener("click", () => {
            fetch("/button-press")
              .then(response => response.text())
              .then(data => {
                console.log(data);
              });
          });
        </script>
      </body>
    </html>
    `);
  });
});

app.get('/button-press', (req, res) => {
  console.log("Button press detected.");
  res.send("Button press detected.");

  fs.readFile('sample.txt', 'utf-8', function (err, data) {
    if (err) throw err;

    console.log(typeof (data)); // string

    console.log(data); // string

  });

  fs.writeFile('sample.txt', 'asdsadasf', 'utf-8', (err) => {
    if (err) {
      console.error(err);
      return;
    }

    console.log('Text appended to file');
  });
  fetch("/");
});

app.listen(port, () => {
  console.log(`App listening at http://localhost:${port}`);
});
