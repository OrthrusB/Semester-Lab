#include <stdio.h>

void poker_test(double *sequence, int n, int d) {
    int patterns[7] = {0};  // Pattern counts
    
    int i, j, k;
    for (i = 0; i < n; i++) {
        int num = (int)(sequence[i] * 100000);  // Convert to 5-digit integer
        int digits[5];
        
        // Extract digits
        for (j = 4; j >= 0; j--) {
            digits[j] = num % 10;
            num = num / 10;
        }
        
        // Count patterns
        int counts[10] = {0};
        int unique = 0;
        for (j = 0; j < d; j++) {
            counts[digits[j]]++;
        }
        for (j = 0; j < 10; j++) {
            if (counts[j] > 0) unique++;
        }
        
        int has_pair = 0, has_three = 0, has_four = 0;
        for (j = 0; j < 10; j++) {
            if (counts[j] == 2) has_pair++;
            if (counts[j] == 3) has_three = 1;
            if (counts[j] == 4) has_four = 1;
        }
        
        if (unique == d) patterns[0]++;
        else if (has_pair == 1 && !has_three) patterns[1]++;
        else if (has_pair == 2) patterns[2]++;
        else if (has_three && !has_pair) patterns[3]++;
        else if (has_three && has_pair) patterns[4]++;
        else if (has_four) patterns[5]++;
        else if (unique == 1) patterns[6]++;
    }

    double expected[7] = {0.3024, 0.5040, 0.1080, 0.0720, 0.0090, 0.0045, 0.0001};
    double chi_square = 0.0;
    
    for (i = 0; i < 7; i++) {
        double diff = patterns[i] - (expected[i] * n);
        chi_square += (diff * diff) / (expected[i] * n);
    }

    const char *names[7] = {"All different", "One pair", "Two pairs", "Three of a kind",
                           "Full house", "Four of a kind", "All same"};
    printf("Pattern frequencies:\n");
    for (i = 0; i < 7; i++) {
        printf("%s: %d\n", names[i], patterns[i]);
    }
    printf("Chi-square statistic: %.4f\n", chi_square);
}

int main() {
    double sequence[] = {0.12345, 0.11234, 0.12333, 0.11112, 0.11111};
    int n = 5;
    poker_test(sequence, n, 5);
    return 0;
}