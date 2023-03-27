// If you want to take JavaScript input into the browser
/*
const n = parseInt(prompt("Enter a positive integer:"));
let i = 1;
let sum = 0;

while (i <= n) {
  sum = sum + i;
  i = i + 1;
}

console.log(`value of sum is ${sum}.`);
*/

// If you want to take input on the JavaScript command line
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question("Enter a positive integer: ", (input) => {
  const n = parseInt(input);
  let i = 1;
  let sum = 0;

  while (i <= n) {
    sum = sum + i;
    i = i + 1;
  }

  console.log(`value of sum is ${sum}.`);

  readline.close();
});
