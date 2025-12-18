#include <iostream>
#include <vector>

using namespace std;

//  generate the next r-combination 
bool nextCombination(vector<int>& comb, int n, int r) {
    for (int i = r - 1; i >= 0; i--) {
        if (comb[i] < n - r + i) {
            comb[i]++;
            for (int j = i + 1; j < r; j++) {
                comb[j] = comb[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

int main() {
    int n, r;

    cout << "Enter the total number of elements: ";
    cin >> n;

    cout << "Enter the number of elements to choose: ";
    cin >> r;

    if (r > n || r <= 0) {
        cout << "Invalid input. r should in between 1 & n.." << endl;
        return 1;
    }

    vector<int> combination(r);

    // Initialize the initial combo
    for (int i = 0; i < r; i++) {
        combination[i] = i;
    }

    cout << "Combinations in lexicographic: " << endl;

    do {
        for (int i = 0; i < r; i++) {
            cout << combination[i] << " ";
        }
        cout << endl;
    } while (nextCombination(combination, n, r));

    return 0;
}
