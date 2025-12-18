#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

float calculateDifference(float Y[], int counter) {
    for (int k = 0; k < counter - 1; k++) {
        Y[k] = Y[k + 1] - Y[k];
    }
    return Y[0];
}

float calculateS(float x, float X[], float h) {
    return (x - X[0]) / h;
}

float calculateForwardInterpolation(float s, float Y[], float h, int counter) {
    float y = Y[0];
    for (int i = 1; i < counter; i++) {
        float term = calculateDifference(Y, counter - i);
        term /= factorial(i);
        term *= pow(s, i);
        term *= h;
        y += term;
    }
    return y;
}

int main() {
    int counter;
    cout << "How many points do you want to enter? ";
    cin >> counter;

    if (counter <= 0) {
        cout << "Invalid number of points. Exiting..." << endl;
        return 1;
    }

    float X[counter], Y[counter];
    cout << "Enter the points (x, y):" << endl;
    for (int i = 0; i < counter; ++i) {
        cout << "x" << i << ": ";
        cin >> X[i];
        cout << "y" << i << ": ";
        cin >> Y[i];
    }

    float h = X[1] - X[0];
    float x;
    cout << "Enter the value for calculation: ";
    cin >> x;

    float s = calculateS(x, X, h);
    float result = calculateForwardInterpolation(s, Y, h, counter);

    cout << "Interpolated value at x = " << x << ": " << result << endl;

    return 0;
}
