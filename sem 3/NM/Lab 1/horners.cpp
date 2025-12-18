#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    float x;
    cout << "Enter the value of x: ";
    cin >> x;

    float coefficients[degree + 1];
    cout << "Enter the coefficients of the polynomial (from highest to lowest degree):" << endl;
    for (int i = degree; i >= 0; --i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    float result = coefficients[0];  // Initialize result with coefficient of highest degree term

    for (int i = 1; i <= degree; ++i) {
        result = result * x + coefficients[i];
    }

    cout << "Result of evaluating the polynomial at x = " << x << ": " << result << endl;

    return 0;
}
