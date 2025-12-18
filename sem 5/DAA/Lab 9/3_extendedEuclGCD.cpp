#include <iostream>
using namespace std;

// Function to implement Extended Euclidean Algorithm
// Returns GCD and updates x and y as references
int extendedGCD(int a, int b, int& x, int& y) {
    // Base case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    // Variables to store results of recursive call
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    
    // Update x and y using results of recursive call
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}

int main() {
    int a, b, x, y;
    
    // Get input from user
    cout << "Enter first number: ";
    cin >> a;
    
    cout << "Enter second number: ";
    cin >> b;
    
    // Ensure numbers are positive
    int originalA = a;
    int originalB = b;
    a = abs(a);
    b = abs(b);
    
    // Calculate GCD and coefficients
    int gcd = extendedGCD(a, b, x, y);
    
    // Display results
    cout << "GCD of " << originalA << " and " << originalB << " is: " << gcd << endl;
    cout << "Coefficients x and y (for " << originalA << "*x + " 
         << originalB << "*y = " << gcd << "): " << endl;
    cout << "x = " << x << ", y = " << y << endl;
    
    // Verify the result
    cout << "Verification: " << originalA << "*" << x << " + " 
         << originalB << "*" << y << " = " << (originalA * x + originalB * y) << endl;
    
    return 0;
}