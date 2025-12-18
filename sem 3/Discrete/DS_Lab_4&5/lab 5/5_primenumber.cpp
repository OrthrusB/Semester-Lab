#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

//  using Fermat's Little Theorem
bool isPrimeFermat(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    srand(time(0)); 
    const int iterations = 5; // Number of iterations 

    for (int i = 0; i < iterations; i++) {
        
        long long a = 2 + rand() % (n - 3);
        
        
        if (mod_pow(a, n - 1, n) != 1) {
            return false; 
        }
    }

    return true; 
}

int main() {
    long long n;

    cout << "Enter a number: ";
    cin >> n;

    if (isPrimeFermat(n)) {
        cout << n << " is prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }

    return 0;
}
