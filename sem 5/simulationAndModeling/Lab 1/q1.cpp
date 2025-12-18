#include <stdio.h>

int main() {
    // Given initial values
    float Y_prev = 80;
    float G[] = {20, 25, 30, 35, 40};
    int num_years = sizeof(G) / sizeof(G[0]);

    // Print header with better alignment
    printf("Year\tG\t\tY\t\tI\t\tC\t\tGrowth in Consumption\n");
    printf("--------------------------------------------------------------------------\n");

    for (int year = 1; year <= num_years; year++) {
        // Calculate I for the current year
        float I = 2 + 0.1 * Y_prev;

        // Calculate Y for the current year
        float Y = 45.45 + 2.27 * (I + G[year - 1]);

        // Calculate T for the current year
        float T = 0.2 * Y;

        // Calculate C for the current year
        float C = 20 + 0.7 * (Y - T);

        // Calculate Growth in Consumption for the current year
        float growth_in_consumption = C - (20 + 0.7 * (Y_prev - 0.2 * Y_prev));

        // Print values with consistent formatting
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", year, G[year - 1], Y, I, C, growth_in_consumption);

        // Set Y_prev to Y for the next iteration
        Y_prev = Y;
    }

    return 0;
}
