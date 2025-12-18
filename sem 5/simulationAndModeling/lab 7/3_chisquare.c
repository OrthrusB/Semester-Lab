#include <stdio.h>

void chi_square_test(double *sequence, int n, int bins) {
    int observed[10] = {0};  // Assuming max 10 bins
    
    int i;
    for (i = 0; i < n; i++) {
        int bin = (int)(sequence[i] * bins);
        if (bin == bins) bin--;  // Handle edge case
        observed[bin]++;
    }
    
    double expected = (double)n / bins;
    double chi_square = 0.0;
    
    for (i = 0; i < bins; i++) {
        double diff = observed[i] - expected;
        chi_square += (diff * diff) / expected;
    }
    
    printf("Observed frequencies: ");
    for (i = 0; i < bins; i++) {
        printf("%d ", observed[i]);
    }
    printf("\nExpected frequency: %.2f\n", expected);
    printf("Chi-square statistic: %.4f\n", chi_square);
    printf("Degrees of freedom: %d\n", bins - 1);
    
    // Using approximate critical value for 5% significance (df=9 for 10 bins)
    double critical = 16.919;
    if (chi_square > critical) {
        printf("Reject null hypothesis: Sequence is not uniformly distributed\n");
    } else {
        printf("Fail to reject null hypothesis: Sequence appears uniformly distributed\n");
    }
}

int main() {
    double sequence[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.95};
    int n = 10;
    chi_square_test(sequence, n, 10);
    return 0;
}