#include <iostream>
#include <cmath>

using namespace std;

float factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void calculateDifferences(float Y[], int counter) {
    for (int i = counter - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            Y[j] = Y[j + 1] - Y[j];
        }
    }
}

float calculateS(float x, float X[], float h, int size) {
    return (x - X[size - 1]) / h;
}

float calculateBackwardInterpolation(float s, float Y[], float h, int counter) {
    float y = Y[counter - 1];
    float term = 1;
    for (int i = 1; i < counter; ++i) {
        term *= (s + i - 1) / i;
        y += term * Y[counter - 1 - i];
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

    float s = calculateS(x, X, h, counter);
    calculateDifferences(Y, counter);

    float result = calculateBackwardInterpolation(s, Y, h, counter);

    cout << "Interpolated value at x = " << x << ": " << result << endl;

    return 0;
}
