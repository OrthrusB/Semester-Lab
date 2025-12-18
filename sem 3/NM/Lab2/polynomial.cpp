#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<double> leastSquares(const vector<double>& x, const vector<double>& y, int degree) {
    int n = x.size();
    int m = degree + 1;

    vector<vector<double>> A(m, vector<double>(m));
    vector<double> B(m);

    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                A[i][j] += pow(x[k], i + j);
            }
        }
        B[i] = 0;
        for (int k = 0; k < n; ++k) {
            B[i] += y[k] * pow(x[k], i);
        }
    }

    vector<double> coefficients(m);
    for (int i = 0; i < m; ++i) {
        coefficients[i] = 0;
        for (int j = 0; j < m; ++j) {
            coefficients[i] += A[i][j] * B[j];
        }
    }

    return coefficients;
}

int main() {
    int size, degree;
    cout << "Enter the number of data points: ";
    cin >> size;

    // Input data points
    vector<double> x(size), y(size);
    cout << "Enter the data points (x, y):" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Data point " << i + 1 << ":" << endl;
        cout << "x: ";
        cin >> x[i];
        cout << "y: ";
        cin >> y[i];
    }

    cout << "Enter the degree of the polynomial to fit: ";
    cin >> degree;

    
    vector<double> coefficients = leastSquares(x, y, degree);

    
    cout << "\nPolynomial Fit:\n";
    cout << "Coefficients of the polynomial:" << endl;
    cout << "f(x) = ";
    for (int i = degree; i >= 0; --i) {
        cout << coefficients[i];
        if (i > 0) {
            cout << "x^" << i << " + ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
