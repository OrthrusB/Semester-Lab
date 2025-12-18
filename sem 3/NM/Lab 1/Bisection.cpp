#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Define the function
float function(float x) {
    return sin(x) + x * x + 5 * x - 9;
}

int main() {
    float xu, xl, xm, error, tolerance;
    int iterations = 0;

    // Input validation for xu (positive output)
    do {
        cout << "Enter a value of xu such that f(xu) > 0: ";
        cin >> xu;
        if (function(xu) < 0)
            cout << "Invalid input! Please enter again." << endl;
    } while (function(xu) < 0);

    // Input validation for xl (negative output)
    do {
        cout << "Enter a value of xl such that f(xl) < 0: ";
        cin >> xl;
        if (function(xl) > 0)
            cout << "Invalid input! Please enter again." << endl;
    } while (function(xl) > 0);

    // Input for tolerance
    cout << "Enter the tolerance value: ";
    cin >> tolerance;

    cout << endl;
    cout << "Iteration\t xu\t\t f(xu)\t\t xl\t\t f(xl)\t\t xm\t\t f(xm)\t\t Error\n";
    
    // Bisection method loop
    do {
        xm = (xu + xl) / 2;
        error = fabs((xm - xu) / xm);

        cout << fixed << setprecision(5) << iterations << "\t\t" << xu << "\t\t" << function(xu) << "\t\t"
             << xl << "\t\t" << function(xl) << "\t\t"
             << xm << "\t\t" << function(xm) << "\t\t" << error << "\n";

        if (function(xm) > 0)
            xu = xm;
        else
            xl = xm;

        iterations++;
    } while (error > tolerance && iterations < 100); // Added a maximum iteration limit

    cout << endl << "Approximate root: " << fixed << setprecision(5) << xm << endl;

    return 0;
}
