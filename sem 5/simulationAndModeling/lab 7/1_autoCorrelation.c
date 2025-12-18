#include <stdio.h>

void autocorrelation_test(double *sequence, int n, int lag) {
    double mean = 0.0;
    int i;
    
    // Calculate mean
    for (i = 0; i < n; i++) {
        mean += sequence[i];
    }
    mean = mean / n;

    double numerator = 0.0;
    double denominator = 0.0;
    
    // Calculate autocorrelation components
    for (i = 0; i < n - lag; i++) {
        numerator += (sequence[i] - mean) * (sequence[i + lag] - mean);
    }
    for (i = 0; i < n; i++) {
        denominator += (sequence[i] - mean) * (sequence[i] - mean);
    }

    double rho = (denominator != 0) ? numerator / denominator : 0;
    
    // Manual square root approximation for standard error (Newton's method)
    double se = 1.0;
    double x = n;
    for (i = 0; i < 10; i++) {  // 10 iterations for approximation
        x = 0.5 * (x + n / x);
    }
    se = se / x;
    
    double z = rho / se;

    printf("Autocorrelation coefficient: %.4f\n", rho);
    printf("Z-score: %.4f\n", z);
    
    // Simplified decision without p-value
    if (z > 1.96 || z < -1.96) {
        printf("Reject null hypothesis: Sequence is not random\n");
    } else {
        printf("Fail to reject null hypothesis: Sequence appears random\n");
    }
}

int main() {
    double sequence[] = {0.12, 0.45, 0.67, 0.89, 0.23, 0.56, 0.78, 0.91, 0.34, 0.67};
    int n = 10;  // Size of sequence
    autocorrelation_test(sequence, n, 1);
    return 0;
}