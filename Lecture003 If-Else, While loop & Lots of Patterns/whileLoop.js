// If you want to take JavaScript input into the browser
/*
let n = parseInt(prompt("Enter a positive integer:"));
let i = 1;

while (i <= n) {
  console.log(i + " ");
  i++;
}
*/

// If you want to take input on the JavaScript command line
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Enter a positive integer: ", (input) => {
  let n = parseInt(input);
  let i = 1;

  while (i <= n) {
    console.log(i + " ");
    i++;
  }

  rl.close();
});
