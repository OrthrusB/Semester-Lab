#include <iostream>
using namespace std;

// Function to compute GCD using Euclidean algorithm (recursive)
int gcd(int a, int b) {
    // Base case: if b becomes 0, return a
    if (b == 0)
        return a;
    
    // Recursive call: GCD(a,b) = GCD(b, a mod b)
    return gcd(b, a % b);
}

// Main function
int main() {
    int num1, num2;
    
    // Get input from user
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    // Ensure numbers are positive
    num1 = abs(num1);
    num2 = abs(num2);
    
    // Calculate and display GCD
    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    
    return 0;
}