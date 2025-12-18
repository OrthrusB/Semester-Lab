// Using the readline module to get user input in Node.js
const readline = require('readline');

// Create an interface for reading input from the terminal
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Recursive function to calculate factorial
const factorial = (n) => {
    if (n < 0) {
        return "Factorial is not defined for negative numbers";
    }
    if (n === 0 || n === 1) {
        return 1; // Base case: 0! = 1, 1! = 1
    }
    return n * factorial(n - 1); // Recursive case
};

// Prompt user for input
rl.question('Enter a number to calculate its factorial: ', (input) => {
    const num = parseInt(input); // Convert input string to integer

    // Check if input is a valid number
    if (isNaN(num)) {
        console.log("Please enter a valid number");
    } else {
        const result = factorial(num);
        console.log(`The factorial of ${num} is: ${result}`);
    }

    rl.close(); // Close the readline interface
});