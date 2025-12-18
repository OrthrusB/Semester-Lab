#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for min
using namespace std;

// Function to calculate minimum edit distance
int editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    // Initialize first row and column
    for(int i = 0; i <= m; i++) {
        dp[i][0] = i;  // Cost of deleting characters from str1
    }
    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;  // Cost of inserting characters from str2
    }
    
    // Fill the DP table
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // No operation needed
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // Deletion
                    dp[i][j-1],    // Insertion
                    dp[i-1][j-1]   // Substitution
                });
            }
        }
    }
    
    return dp[m][n];
}

// Function to print the edit operations
void printEditOperations(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    // Fill DP table (same as above)
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // Deletion
                    dp[i][j-1],    // Insertion
                    dp[i-1][j-1]   // Substitution
                });
            }
        }
    }
    
    // Backtrack to find operations
    int i = m, j = n;
    cout << "Edit operations:\n";
    while(i > 0 || j > 0) {
        if(i > 0 && j > 0 && str1[i-1] == str2[j-1]) {
            i--;
            j--;
        }
        else if(i > 0 && dp[i][j] == dp[i-1][j] + 1) {
            cout << "Delete '" << str1[i-1] << "' from str1\n";
            i--;
        }
        else if(j > 0 && dp[i][j] == dp[i][j-1] + 1) {
            cout << "Insert '" << str2[j-1] << "' into str1\n";
            j--;
        }
        else {
            cout << "Substitute '" << str1[i-1] << "' with '" 
                 << str2[j-1] << "'\n";
            i--;
            j--;
        }
    }
}

int main() {
    string str1 = "sunday";
    string str2 = "saturday";
    
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    
    int distance = editDistance(str1, str2);
    cout << "Minimum edit distance: " << distance << endl;
    
    printEditOperations(str1, str2);
    
    return 0;
}