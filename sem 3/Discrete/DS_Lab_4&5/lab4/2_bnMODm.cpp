#include <iostream>

using namespace std;


long long mod_pow(long long base, long long exponent, long long mod) {
    if (mod == 1) 
    
    return 0; 

    if (exponent == 0) 
    
    return 1;

    long long result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        exponent = exponent >> 1;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long b, n, m;

    cout << "Enter base: ";
    cin >> b;

    cout << "Enter exponent: ";
    cin >> n;

    cout << "Enter modulus: ";
    cin >> m;

    if (m <= 0) {
        cout << "Modulus  must be a positive integer." << endl;
        return 1;
    }

    long long result = mod_pow(b, n, m);

    cout << b << "^" << n << " mod " << m << " is " << result << endl;

    return 0;
}
