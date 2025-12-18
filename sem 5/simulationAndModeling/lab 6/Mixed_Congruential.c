#include <stdio.h>

int main() {
    int X0 = 11;    // Initial seed
    int m = 100;    // Modulus
    int a = 5;      // Multiplier
    int c = 13;     // Increment
    int Xn;         // Current random number
    int i;          // Loop counter
    
    printf("Generating 50 random numbers using Mixed Congruential Method:\n");
    printf("X0 = %d, m = %d, a = %d, c = %d\n", X0, m, a, c);
    printf("Random Numbers:\n");
    
    Xn = X0;        // Start with seed
    for (i = 0; i < 50; i++) {
        Xn = (a * Xn + c) % m;  // Xn+1 = (a * Xn + c) mod m
        printf("%d ", Xn);
        if ((i + 1) % 10 == 0)  // Print 10 numbers per line
            printf("\n");
    }
    printf("\n");
    
    return 0;
}