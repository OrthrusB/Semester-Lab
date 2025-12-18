#include <stdio.h>
#include <math.h>

int main() {
    double lambda = 1.0;          // Arrival rate: 1 customer per minute
    double service_time = 20.0 / 60.0; // Service time: 20 seconds = 1/3 minute
    double mu = 1.0 / service_time;    // Service rate: 3 customers per minute
    double walking_time = 1.5;    // Time to reach seat: 1.5 minutes
    double time_before_game = 2.0; // Time before kick-off: 2 minutes

    // Calculate utilization factor (ρ)
    double rho = lambda / mu;

    // Calculate probability of no wait (P0)
    double P0 = 1.0 - rho;

    // Average time in system (W) = avg time in queue + avg service time
    double W = 1.0 / (mu - lambda);

    // Total time = time in system + walking time
    double total_time = W + walking_time;

    printf("Utilization factor (rho): %.2f\n", rho);
    printf("Probability of no wait (P0): %.2f\n", P0);
    printf("Average time in system (W): %.2f minutes\n", W);
    printf("Total expected time to be seated: %.2f minutes\n", total_time);

    // Check if fan can be seated before kick-off
    if (total_time <= time_before_game) {
        printf("Yes, the sports fan can expect to be seated for the kick-off\n");
    } else {
        printf("No, the sports fan cannot expect to be seated for the kick-off\n");
    }

    return 0;
}
