#include <stdio.h>

int main() {
    // Transition probabilities
    double P_CC = 0.90;    // Coke -> Coke
    double P_CP = 0.10;    // Coke -> Pepsi
    double P_PC = 0.20;    // Pepsi -> Coke
    double P_PP = 0.80;    // Pepsi -> Pepsi

    // Given: Current state is Pepsi
    // Calculate probability of Coke after two purchases
    // Two possible paths:
    // 1. Pepsi -> Pepsi -> Coke
    // 2. Pepsi -> Coke -> Coke

    // Step 1: Pepsi today to next purchase states
    double prob_P_to_P = P_PP;    // Pepsi -> Pepsi
    double prob_P_to_C = P_PC;    // Pepsi -> Coke

    // Step 2: Next purchase to purchase after that
    // Path 1: P -> P -> C
    double path1 = prob_P_to_P * P_PC;
    // Path 2: P -> C -> C
    double path2 = prob_P_to_C * P_CC;

    // Total probability = sum of both paths
    double total_prob = path1 + path2;

    printf("Transition Probabilities:\n");
    printf("Coke -> Coke: %.2f\n", P_CC);
    printf("Coke -> Pepsi: %.2f\n", P_CP);
    printf("Pepsi -> Coke: %.2f\n", P_PC);
    printf("Pepsi -> Pepsi: %.2f\n", P_PP);
    printf("\nProbability of purchasing Coke after two purchases given Pepsi now:\n");
    printf("Path 1 (P->P->C): %.2f * %.2f = %.4f\n", P_PP, P_PC, path1);
    printf("Path 2 (P->C->C): %.2f * %.2f = %.4f\n", P_PC, P_CC, path2);
    printf("Total Probability = %.4f or %.2f%%\n", total_prob, total_prob * 100);

    return 0;
}