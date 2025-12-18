#include <iostream>
#include <vector>
using namespace std;

// Function to print the subset
void printSubset(vector<int>& subset) {
    cout << "Subset found: ";
    for(int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Backtracking function to find subset sum
void subsetSum(vector<int>& set, vector<int>& subset, int target, 
               int sum, int index, int n) {
    // Base case: if current sum equals target
    if(sum == target) {
        printSubset(subset);
        return;
    }
    
    // If sum exceeds target or we've reached end of array
    if(sum > target || index >= n) {
        return;
    }
    
    // Include current element and recurse
    subset.push_back(set[index]);
    subsetSum(set, subset, target, sum + set[index], index + 1, n);
    
    // Exclude current element and recurse
    subset.pop_back();
    subsetSum(set, subset, target, sum, index + 1, n);
}

// Utility function to initiate subset sum solving
void solveSubsetSum(vector<int>& set, int target) {
    vector<int> subset;
    int n = set.size();
    cout << "Finding subsets with sum " << target << endl;
    subsetSum(set, subset, target, 0, 0, n);
}

int main() {
    // Example usage
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int target = 9;
    
    cout << "Given set: ";
    for(int i = 0; i < set.size(); i++) {
        cout << set[i] << " ";
    }
    cout << endl;
    
    solveSubsetSum(set, target);
    
    return 0;
}