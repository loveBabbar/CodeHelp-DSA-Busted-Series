// If you want to take JavaScript input into the browser
/*
let n = parseInt(prompt("Enter the value of n:"));

let i = 1;

while(i <= n) {
  let j = 1;
  while(j <= n) {
    process.stdout.write("*");
    j = j + 1;
  }
  process.stdout.write("\n");
  i = i + 1;
}
*/

// If you want to take input on the JavaScript command line
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question("Enter the value of n: ", (input) => {
  const n = parseInt(input);
  let i = 1;

  while (i <= n) {
    let j = 1;
    while (j <= n) {
      process.stdout.write("*");
      j = j + 1;
    }
    process.stdout.write("\n");
    i = i + 1;
  }

  readline.close();
});
