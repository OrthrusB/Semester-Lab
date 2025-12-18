#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float x) {
    return sin(x) + x * x + 5 * x - 9;
}

float derivative(float x) {
    return cos(x) + 2 * x + 5;
}

int main() {
    float initial_guess;
    cout << "Enter an initial guess: ";
    cin >> initial_guess;
    cout << endl;

    float x_old, x_new, fx, dx, error;
    int iteration = 0;
    const float tolerance = 0.0001;

    x_new = initial_guess;

    cout << "Iteration\t x(old)\t\t f(x)(old)\t f'(x)(old)\t x(new)\t\t Error\n";

    do {
        x_old = x_new;
        fx = function(x_old);
        dx = derivative(x_old);
        x_new = x_old - (fx / dx);
        error = fabs((x_new - x_old) / x_new);

        cout << setw(5) << iteration << "\t\t" << setw(8) << x_old << "\t\t" << setw(8) << fx << "\t\t" << setw(8) << dx << "\t\t" << setw(8) << x_new << "\t\t" << error << "\n";
        iteration++;
    } while (error > tolerance && iteration < 100); // Limit iterations to avoid infinite loop

    cout << endl << "Final root: " << fixed << setprecision(5) << x_new << endl;
    return 0;
}
