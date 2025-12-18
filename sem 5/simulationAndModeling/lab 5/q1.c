#include <stdio.h>

int main() {
    // Transition probabilities
    double P_RR = 0.40;    // Rain -> Rain
    double P_RN = 0.60;    // Rain -> Not Rain
    double P_NR = 0.20;    // Not Rain -> Rain
    double P_NN = 0.80;    // Not Rain -> Not Rain

    // Given: Today is Not Rainy
    // Calculate probability for day after tomorrow (2 steps)
    // Two possible paths:
    // 1. Not Rain -> Not Rain -> Not Rain
    // 2. Not Rain -> Rain -> Not Rain

    // Step 1: Not Rain today to tomorrow states
    double prob_N_to_N = P_NN;    // Not Rain -> Not Rain
    double prob_N_to_R = P_NR;    // Not Rain -> Rain

    // Step 2: Tomorrow to day after tomorrow
    // Path 1: N -> N -> N
    double path1 = prob_N_to_N * P_NN;
    // Path 2: N -> R -> N
    double path2 = prob_N_to_R * P_RN;

    // Total probability = sum of both paths
    double total_prob = path1 + path2;

    printf("Transition Probabilities:\n");
    printf("Rain -> Rain: %.2f\n", P_RR);
    printf("Rain -> Not Rain: %.2f\n", P_RN);
    printf("Not Rain -> Rain: %.2f\n", P_NR);
    printf("Not Rain -> Not Rain: %.2f\n", P_NN);
    printf("\nProbability of Not Rain day after tomorrow given Not Rain today:\n");
    printf("Path 1 (N->N->N): %.2f * %.2f = %.4f\n", P_NN, P_NN, path1);
    printf("Path 2 (N->R->N): %.2f * %.2f = %.4f\n", P_NR, P_RN, path2);
    printf("Total Probability = %.4f or %.2f%%\n", total_prob, total_prob * 100);

    return 0;
}