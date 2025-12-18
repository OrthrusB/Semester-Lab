#include <stdio.h>

int main() {
    int n = 10;         // Sample size (small for demonstration)
    float sample[10];   // Array to store random numbers between 0 and 1
    float Fn[10];       // Empirical CDF (F_n(x))
    float F[10];        // Theoretical CDF (uniform distribution, F(x) = x)
    float D_plus;       // Maximum positive deviation
    float D_minus;      // Maximum negative deviation
    float D;            // K-S statistic
    int i, j;           // Loop counters
    int Xn = 7;         // Seed for simple random generation
    int m = 100;        // Modulus for random generation
    int a = 5;          // Multiplier for random generation
    int c = 3;          // Increment for random generation
    
    // Generate random numbers (0 to 1) using mixed congruential method
    printf("Generated Random Numbers (0 to 1):\n");
    for (i = 0; i < n; i++) {
        Xn = (a * Xn + c) % m;          // Generate integer random number
        sample[i] = (float)Xn / m;      // Normalize to [0, 1]
        printf("%.3f ", sample[i]);
    }
    printf("\n");
    
    // Sort the sample in ascending order (bubble sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sample[j] > sample[j + 1]) {
                float temp = sample[j];
                sample[j] = sample[j + 1];
                sample[j + 1] = temp;
            }
        }
    }
    
    // Compute empirical CDF (F_n(x)) and theoretical CDF (F(x))
    printf("\nSample (sorted), F_n(x), F(x), Differences:\n");
    D_plus = 0.0;
    D_minus = 0.0;
    for (i = 0; i < n; i++) {
        Fn[i] = (float)(i + 1) / n;     // Empirical CDF: (i+1)/n
        F[i] = sample[i];               // Theoretical CDF: x (for uniform [0,1])
        
        // Compute deviations
        float diff_plus = Fn[i] - F[i];   // F_n(x) - F(x)
        float diff_minus = F[i] - Fn[i];  // F(x) - F_n(x)
        
        if (diff_plus > D_plus) D_plus = diff_plus;
        if (diff_minus > D_minus) D_minus = diff_minus;
        
        printf("x = %.3f, F_n(x) = %.3f, F(x) = %.3f, D+ = %.3f, D- = %.3f\n", 
               sample[i], Fn[i], F[i], diff_plus, diff_minus);
    }
    
    // K-S statistic D = max(D+, D-)
    D = D_plus > D_minus ? D_plus : D_minus;
    
    printf("\nK-S Test Results:\n");
    printf("D+ = %.3f\n", D_plus);
    printf("D- = %.3f\n", D_minus);
    printf("K-S Statistic (D) = %.3f\n", D);
    
    // Critical value for n = 10, alpha = 0.05 is approximately 0.409 (from K-S table)
    float critical_value = 0.409;
    printf("Critical value (alpha = 0.05, n = 10) = %.3f\n", critical_value);
    if (D <= critical_value) {
        printf("Conclusion: Do not reject H0 (sample is uniform)\n");
    } else {
        printf("Conclusion: Reject H0 (sample is not uniform)\n");
    }
    
    return 0;
}