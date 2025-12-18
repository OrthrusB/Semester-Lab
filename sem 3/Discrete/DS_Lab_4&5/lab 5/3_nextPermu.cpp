#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Original permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    
    while (next_permutation(nums.begin(), nums.end())) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
