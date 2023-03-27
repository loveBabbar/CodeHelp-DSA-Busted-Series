// If you want to take JavaScript input into the browser
/*
let n = prompt("Enter a positive integer: ");
n = parseInt(n);
let i = 2;
let isPrime = true;

while (i < n) {
  if (n % i === 0) {
    isPrime = false;
    alert(`${n} is not prime. It is divisible by ${i}.`);
  }
  i = i + 1;
}

if (isPrime) {
  alert(`${n} is a prime number.`);
}
*/

// If you want to take input on the JavaScript command line
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question("Enter a positive integer: ", (input) => {
  const n = parseInt(input);
  let i = 2;
  let isPrime = true;

  while (i < n) {
    if (n % i === 0) {
      isPrime = false;
      console.log(`${n} is not prime. It is divisible by ${i}.`);
    }
    i = i + 1;
  }

  if (isPrime) {
    console.log(`${n} is a prime number.`);
  }

  readline.close();
});