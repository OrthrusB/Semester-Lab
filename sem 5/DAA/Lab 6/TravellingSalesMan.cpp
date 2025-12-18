#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = INT_MAX / 2; // Avoid overflow

int TSP(vector<vector<int>>& distan, vector<vector<int>>& DP, int mark, int position, int n, int completed_visit) {
    if (mark == completed_visit)
        return distan[position][0];
    
    if (DP[mark][position] != -1)
        return DP[mark][position];
    
    int answer = MAX;
    for (int city = 0; city < n; city++) {
        if ((mark & (1 << city)) == 0) {
            int newAnswer = distan[position][city] + TSP(distan, DP, mark | (1 << city), city, n, completed_visit);
            answer = min(answer, newAnswer);
        }
    }
    return DP[mark][position] = answer;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Invalid number of cities (must be 1-20)" << endl;
        return 1;
    }

    // Dynamic allocation
    vector<vector<int>> distan(n, vector<int>(n));
    vector<vector<int>> DP(1 << n, vector<int>(n, -1));
    int completed_visit = (1 << n) - 1;

    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distan[i][j];
            if (distan[i][j] < 0) {
                cout << "Negative distances not allowed" << endl;
                return 1;
            }
        }
    }

    int result = TSP(distan, DP, 1, 0, n, completed_visit);
    if (result >= MAX) {
        cout << "No valid tour possible" << endl;
    } else {
        cout << "Minimum Distance Travelled -> " << result << endl;
    }

    return 0;
}