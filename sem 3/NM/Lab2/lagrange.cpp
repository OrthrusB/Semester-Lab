#include <iostream>
#include <vector>

using namespace std;

float lagrangeInterpolation(float x, const vector<float>& X, const vector<float>& Y) {
    float result = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        float term = Y[i];
        for (size_t j = 0; j < X.size(); ++j) {
            if (i != j) {
                term *= (x - X[j]) / (X[i] - X[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int counter;
    cout << "Enter the number of points: ";
    cin >> counter;

    if (counter <= 0) {
        cout << "Invalid number of points. Exiting..." << endl;
        return 1;
    }

    vector<float> X(counter), Y(counter);

    cout << "Enter the points (x, y):" << endl;
    for (int i = 0; i < counter; ++i) {
        cout << "x" << i << ": ";
        cin >> X[i];
        cout << "y" << i << ": ";
        cin >> Y[i];
    }

    float x;
    cout << "Enter the value for calculation: ";
    cin >> x;

    float result = lagrangeInterpolation(x, X, Y);
    cout << "Interpolated value at x = " << x << "is " << result << endl;

    return 0;
}
