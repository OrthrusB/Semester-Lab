#include <iostream>
using namespace std;

// Function to find modular multiplicative inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1)
        return 0;
    
    // Apply extended Euclid Algorithm
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}

// Function to find the solution using Chinese Remainder Theorem
int findCRT(int num[], int rem[], int k) {
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    
    // Initialize result
    int result = 0;
    
    // Apply CRT formula
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];  // Partial product
        result += rem[i] * pp * modInverse(pp, num[i]);
    }
    
    return result % prod;
}

// Function to check if moduli are pairwise coprime
bool arePairwiseCoprime(int num[], int k) {
    for (int i = 0; i < k-1; i++)
        for (int j = i+1; j < k; j++) {
            int a = num[i], b = num[j];
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            if (a != 1)  // GCD is not 1
                return false;
        }
    return true;
}

int main() {
    int k;
    
    // Get number of equations
    cout << "Enter the number of congruences: ";
    cin >> k;
    
    int num[k], rem[k];
    
    // Get moduli and remainders from user
    for (int i = 0; i < k; i++) {
        cout << "Enter modulus " << i+1 << ": ";
        cin >> num[i];
        cout << "Enter remainder " << i+1 << " (for x ≡ r (mod m)): ";
        cin >> rem[i];
        
        // Ensure remainder is non-negative and less than modulus
        rem[i] = (rem[i] % num[i] + num[i]) % num[i];
    }
    
    // Check if moduli are pairwise coprime
    if (!arePairwiseCoprime(num, k)) {
        cout << "Error: Moduli must be pairwise coprime for CRT to work!" << endl;
        return 1;
    }
    
    // Calculate and display result
    int result = findCRT(num, rem, k);
    cout << "The solution x is: " << result << endl;
    
    // Verify the solution
    cout << "Verification:" << endl;
    for (int i = 0; i < k; i++)
        cout << result << " ≡ " << rem[i] << " (mod " << num[i] << ")" << endl;
    
    return 0;
}