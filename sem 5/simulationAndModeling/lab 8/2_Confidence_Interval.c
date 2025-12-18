#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate sample mean
double calculateMean(double arr[], int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate sample standard deviation
double calculateStdDev(double arr[], int n, double mean) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / (n - 1));
}

int main() {
    int n;
    double confidence_level;
    
    // Get sample size
    printf("Enter the sample size: ");
    scanf("%d", &n);
    
    if(n <= 1) {
        printf("Sample size must be greater than 1!\n");
        return 1;
    }
    
    // Allocate array for sample data
    double *sample = (double*)malloc(n * sizeof(double));
    
    // Get sample data
    printf("Enter %d sample values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &sample[i]);
    }
    
    // Get confidence level
    printf("Enter confidence level (e.g., 95 for 95%%): ");
    scanf("%lf", &confidence_level);
    
    // Calculate sample mean and standard deviation
    double mean = calculateMean(sample, n);
    double std_dev = calculateStdDev(sample, n, mean);
    
    // Calculate standard error (using t-distribution approximation)
    // For simplicity, using z-scores for common confidence levels
    double z_score;
    if(confidence_level == 95) z_score = 1.96;
    else if(confidence_level == 90) z_score = 1.645;
    else if(confidence_level == 99) z_score = 2.576;
    else {
        printf("Using default 95%% confidence level\n");
        z_score = 1.96;
    }
    
    double margin_error = z_score * (std_dev / sqrt(n));
    
    // Calculate confidence interval
    double lower_bound = mean - margin_error;
    double upper_bound = mean + margin_error;
    
    // Display results
    printf("\nResults:\n");
    printf("Sample Mean: %.4f\n", mean);
    printf("Sample Standard Deviation: %.4f\n", std_dev);
    printf("Margin of Error: %.4f\n", margin_error);
    printf("Confidence Interval (%.0f%%): [%.4f, %.4f]\n", 
           confidence_level, lower_bound, upper_bound);
    
    // Free allocated memory
    free(sample);
    
    return 0;
}