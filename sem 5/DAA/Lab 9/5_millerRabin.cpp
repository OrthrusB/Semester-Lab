#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to compute (a^b) % m efficiently
long long modPow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Miller-Rabin witness function
bool millerRabinTest(long long d, long long n, long long a) {
    long long x = modPow(a, d, n);
    
    if (x == 1 || x == n - 1)
        return true;
    
    // Square x repeatedly and check
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

// Function to check if n is prime using Miller-Rabin
bool isPrime(long long n, int k = 5) {
    // Handle base cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    
    // Write n-1 as 2^r * d
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    
    // Witness loop with k iterations
    srand(time(0));
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4); // Random base between 2 and n-2
        if (!millerRabinTest(d, n, a))
            return false; // Composite
    }
    return true; // Probably prime
}

int main() {
    long long n;
    
    // Get input from user
    cout << "Enter a number to test for primality: ";
    cin >> n;
    
    // Ensure number is positive
    if (n <= 0) {
        cout << "Please enter a positive number!" << endl;
        return 1;
    }
    
    // Check and display result
    if (isPrime(n)) {
        cout << n << " is prime (with high probability)." << endl;
    } else {
        cout << n << " is composite." << endl;
    }
    
    return 0;
}