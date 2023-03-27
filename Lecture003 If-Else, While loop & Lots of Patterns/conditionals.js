// If you want to take JavaScript input into the browser
/*
let a = parseInt(prompt("Enter the value of a"));
if (a > 0) {
  console.log("a is positive");
} else if (a < 0) {
  console.log("a is negative");
} else {
  console.log("a is 0");
}
*/

// If you want to take input on the JavaScript command line
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question("Enter the value of a: ", (input) => {
  const a = parseInt(input);
  if (a > 0) {
    console.log("a is positive");
  } else if (a < 0) {
    console.log("a is negative");
  } else {
    console.log("a is 0");
  }
  readline.close();
});