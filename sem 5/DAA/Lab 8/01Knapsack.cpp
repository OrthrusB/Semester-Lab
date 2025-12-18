#include <iostream>
#include <vector>
using namespace std;

class Knapsack {
private:
    int n;                  // number of items
    int capacity;          // knapsack capacity
    vector<int> weights;   // weights of items
    vector<int> values;    // values of items
    vector<int> current;   // current solution
    vector<int> best;      // best solution found
    int maxValue;         // maximum value achieved
    int currWeight;       // current weight
    int currValue;        // current value

    // Print the solution
    void printSolution(const vector<int>& sol) {
        cout << "Items included (1 = included, 0 = not included): ";
        for(int i = 0; i < n; i++) {
            cout << sol[i] << " ";
        }
        cout << endl;
    }

    // Backtracking function
    void knapsackBT(int level) {
        // Base case: reached end of items
        if(level == n) {
            if(currValue > maxValue) {
                maxValue = currValue;
                best = current;
            }
            return;
        }

        // Try excluding current item (0)
        current[level] = 0;
        knapsackBT(level + 1);

        // Try including current item (1) if possible
        if(currWeight + weights[level] <= capacity) {
            current[level] = 1;
            currWeight += weights[level];
            currValue += values[level];
            knapsackBT(level + 1);
            
            // Backtrack
            currWeight -= weights[level];
            currValue -= values[level];
        }
    }

public:
    Knapsack(vector<int>& w, vector<int>& v, int cap) {
        weights = w;
        values = v;
        capacity = cap;
        n = w.size();
        current.resize(n, 0);
        best.resize(n, 0);
        maxValue = 0;
        currWeight = 0;
        currValue = 0;
    }

    void solve() {
        cout << "Knapsack Capacity: " << capacity << endl;
        cout << "Item Weights: ";
        for(int w : weights) cout << w << " ";
        cout << "\nItem Values: ";
        for(int v : values) cout << v << " ";
        cout << endl;

        knapsackBT(0);

        cout << "\nMaximum value achievable: " << maxValue << endl;
        printSolution(best);
    }
};

int main() {
    // Example usage
    vector<int> weights = {2, 3, 4, 5};     // weights of items
    vector<int> values = {3, 4, 5, 6};      // values of items
    int capacity = 10;                      // knapsack capacity

    Knapsack ks(weights, values, capacity);
    ks.solve();

    return 0;
}