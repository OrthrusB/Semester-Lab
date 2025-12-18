#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci series
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num_terms;

    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> num_terms;

    cout << "Fibonacci series up to " << num_terms << " terms:\n";
    for (int i = 0; i < num_terms; ++i) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}
