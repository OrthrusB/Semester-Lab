#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void calculateDifferences(float Y[], const float X[], int i, int counter) {
    for (int k = 0; k < counter - i - 1; k++) {
        Y[k] = (Y[k + 1] - Y[k]) / (X[k + 1 + i] - X[k]);
    }
}

float recursiveProduct(float x, const float X[], int i) {
    if (i == -1) {
        return 1;
    } else {
        return (x - X[i]) * recursiveProduct(x, X, i - 1);
    }
}

float interpolate(float data[], const float X[], const float Y[], int counter, float x) {
    float y = Y[0];
    for (int i = 0; i < counter; i++) {
        y += data[i] * recursiveProduct(x, X, i);
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

    vector<float> X(counter), Y(counter), Ynew(counter), data(counter);

    cout << "Enter the points (x, y):" << endl;
    for (int i = 0; i < counter; ++i) {
        cout << "value of x" << i << ": ";
        cin >> X[i];
        cout << "value of y" << i << ": ";
        cin >> Y[i];
        Ynew[i] = Y[i];
    }

    data[0] = Y[0];
    for (int i = 0; i < counter - 1; i++) {
        calculateDifferences(Ynew.data(), X.data(), i, counter);
        data[i + 1] = Ynew[0];
    }

    float x;
    cout << "Enter the value for calculation: ";
    cin >> x;

    float result = interpolate(data.data(), X.data(), Y.data(), counter, x);

    cout << "Hence, f(" << x << ") = " << result;

    return 0;
}
