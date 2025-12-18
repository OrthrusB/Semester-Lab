#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>  // Include this header for fabs()

int main() {
    long long total_points, points_inside_circle = 0;  // Changed to long long for larger numbers
    double x, y, pi_estimate;
    
    printf("Enter the total number of points: ");
    scanf("%lld", &total_points);  // Changed format specifier to %lld
    
    if (total_points <= 0) {
        printf("Please enter a positive number of points\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));
    
    for (long long i = 0; i < total_points; i++) {
        // Generate random points in the range [0, 1]
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        
        // Check if the point is inside the quarter circle
        if (x * x + y * y <= 1.0) {
            points_inside_circle++;
        }
    }
    
    // Calculate and display the estimated value of PI
    pi_estimate = 4.0 * points_inside_circle / total_points;
    printf("Points inside circle: %lld\n", points_inside_circle);
    printf("Total points: %lld\n", total_points);
    printf("Estimated value of PI: %.10f\n", pi_estimate);
    printf("Actual value of PI:   %.10f\n", 3.1415926536);
    printf("Absolute error:       %.10f\n", 
           fabs(pi_estimate - 3.1415926536));  // Now fabs() is recognized

    return 0;
}
