#include<iostream>
#include<cmath>
using namespace std;

// Define the function to be integrated
float f(float x) {
    return pow(x, 3) + 1;
}

// Apply the trapezoidal rule for single integration
float trapezoidalRule(float a, float b, int n, float (*func)(float)) {
    float h = (b - a) / n; // Step size
    float integral = 0.5 * (func(a) + func(b)); // Start with the end points

    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        integral += func(x); // Sum up the values of the function
    }

    integral *= h; // Multiply by the step size
    return integral;
}

int main() {
    float a, b; // Integration bounds
    cout << "Enter Lower Limit: ";
    cin >> a;
    cout << "Enter Upper Limit: ";
    cin >> b;

    int n; // Number of intervals
    cout << "Enter number of intervals: ";
    cin >> n;

    float integral = trapezoidalRule(a, b, n, f); // Compute the integral using the trapezoidal rule

    cout << "Single Integral using Trapezoidal Rule: " << integral << endl;

    return 0;
}
