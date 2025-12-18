#include <stdio.h>

int main() {
    int X0 = 13;    // Initial seed
    int m = 1000;   // Modulus
    int a = 15;     // Multiplier
    int c = 7;      // Increment (though typically c = 0 in multiplicative, included as per input)
    int Xn;         // Current random number
    int i;          // Loop counter
    
    printf("Generating 50 random numbers using Multiplicative Congruential Method:\n");
    printf("X0 = %d, m = %d, a = %d, c = %d\n", X0, m, a, c);
    printf("Random Numbers:\n");
    
    Xn = X0;        // Start with seed
    for (i = 0; i < 50; i++) {
        Xn = (a * Xn) % m;  // Xn+1 = (a * Xn) mod m (ignoring c as per pure multiplicative method)
        printf("%d ", Xn);
        if ((i + 1) % 10 == 0)  // Print 10 numbers per line
            printf("\n");
    }
    printf("\n");
    
    return 0;
}