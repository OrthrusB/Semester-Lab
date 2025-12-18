#include <iostream>
#include <cmath>
using namespace std;

float f(float x) {
    return 1 / x;
}

int main() {
    float a, b, h, result;
    cout << "Enter Lower Limit: ";
    cin >> a;
    cout << "Enter Upper Limit: ";
    cin >> b;

    int x, y;
    cout << "Enter Value of i in Rij: ";
    cin >> x;
    cout << "Enter Value of j in Rij: ";
    cin >> y;

    float A[x][x], sum;
    
    for (int i = 0; i < x; i++) {
        h = (b - a) / pow(2, i);
        sum = 0;
        if (i == 0) {
            A[i][0] = h / 2 * (f(a) + f(b));
        } else {
            for (int k = 1; k <= pow(2, i - 1); k++) {
                sum += f(a + (2 * k - 1) * h);
            }
            A[i][0] = A[i - 1][0] / 2 + h * sum;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 1; j <= i; j++) {
            A[i][j] = (pow(4, j) * A[i][j - 1] - A[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    cout << "Output: " << A[x - 1][y];

    return 0;
}
