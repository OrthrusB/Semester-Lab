#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float x) {
    return exp(-x);
}

int main() {
    float initial_guess;

    // Input initial guess from the user
    cout << "Enter the initial guess: ";
    cin >> initial_guess;
    
    // Variables for iteration and storing results
    int iteration = 1;
    float current_x = initial_guess;
    float next_x, error;

    cout << endl << "Iteration\t x_n\t\t x_{n+1}\t Error\n";

    do {
        // Compute the next approximation using the fixed-point iteration formula
        next_x = function(current_x);
        
        // Calculate the error
        error = abs((next_x - current_x) / next_x);

        // Output current iteration results
        cout << fixed << setprecision(6) << setw(5) << iteration << "\t\t" << setw(8) << current_x << "\t" << setw(8) << next_x << "\t" << setw(8) << error << "\n";

        // Update current_x for the next iteration
        current_x = next_x;
        
        // Increment iteration count
        iteration++;
    } while (error > 0.05 && iteration <= 100); // Convergence criterion and iteration limit

    // Output final result
    cout << endl << "Final output: " << fixed << setprecision(6) << current_x << endl;

    return 0;
}
