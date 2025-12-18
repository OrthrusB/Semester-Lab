#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float x) {
    return sin(x) + x * x + 5 * x - 9;
}

float secant(float x1, float x2, float f1, float f2) {
    return x2 - ((x2 - x1) / (f2 - f1)) * f2;
}

int main() {
    float initial_guess1, initial_guess2;

    cout << "Enter the first initial guess: ";
    cin >> initial_guess1;
    cout << "Enter the second initial guess: ";
    cin >> initial_guess2;

    cout << endl;
    int iteration = 0;
    float xi_minus_1, xi, f_xi_minus_1, f_xi, xi_plus_1, f_xi_plus_1, error;
    const float tolerance = 0.0001;

    cout << "Iteration\t xi-1\t\t f(xi-1)\t xi\t\t f(xi)\t\t xi+1\t\t f(xi+1)\t Error\n";

    do {
        xi_minus_1 = initial_guess1;
        f_xi_minus_1 = function(xi_minus_1);

        xi = initial_guess2;
        f_xi = function(xi);

        xi_plus_1 = secant(xi_minus_1, xi, f_xi_minus_1, f_xi);
        f_xi_plus_1 = function(xi_plus_1);

        error = fabs((xi_plus_1 - xi) / xi_plus_1);

        cout << setw(5) << iteration << "\t\t" << setw(8) << xi_minus_1 << "\t" << setw(8) << f_xi_minus_1 << "\t" << setw(8) << xi << "\t" << setw(8) << f_xi << "\t" << setw(8) << xi_plus_1 << "\t" << setw(8) << f_xi_plus_1 << "\t" << error << "\n";

        initial_guess1 = xi;
        initial_guess2 = xi_plus_1;

        iteration++;
    } while (error > tolerance && iteration < 100); // Limit iterations to avoid infinite loop

    cout << endl << "Final root: " << fixed << setprecision(5) << xi_plus_1 << endl;

    return 0;
}
