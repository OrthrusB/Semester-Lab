#include <stdio.h>
#include <stdlib.h>

// Function to calculate sample mean (point estimate)
double calculateSampleMean(double arr[], int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int main() {
    int n;
    double population_mean;
    
    // Get sample size
    printf("Enter the sample size: ");
    scanf("%d", &n);
    
    // Input validation
    if(n <= 0) {
        printf("Sample size must be positive!\n");
        return 1;
    }
    
    // Allocate array for sample data
    double *sample = (double*)malloc(n * sizeof(double));
    
    // Get sample data
    printf("Enter %d sample values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &sample[i]);
    }
    
    // Get population mean
    printf("Enter the population mean: ");
    scanf("%lf", &population_mean);
    
    // Calculate point estimate (sample mean)
    double point_estimate = calculateSampleMean(sample, n);
    
    // Calculate bias (difference between point estimate and population mean)
    double bias = point_estimate - population_mean;
    
    // Display results
    printf("\nResults:\n");
    printf("Point Estimate (Sample Mean): %.4f\n", point_estimate);
    printf("Population Mean: %.4f\n", population_mean);
    printf("Bias: %.4f\n", bias);
    
    // Free allocated memory
    free(sample);
    
    return 0;
}