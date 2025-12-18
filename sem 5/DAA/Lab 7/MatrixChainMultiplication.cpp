#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    // Base case: single matrix
    for (int i = 0; i < n-1; i++) {
        dp[i][i+1] = 0;
    }
    
    // Length of chain
    for (int len = 2; len < n; len++) {
        // Starting index
        for (int i = 0; i < n-len; i++) {
            int j = i + len;
            // Try different k positions
            for (int k = i+1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    cout << matrixMultiplication(arr) << endl;
    return 0;
}