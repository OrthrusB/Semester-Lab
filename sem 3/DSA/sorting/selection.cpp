#include <iostream>
using namespace std;

void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

int main() {
    int n;

    // Prompt the user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Validate the input for a positive integer
    if (n <= 0) {
        cout << "Invalid size. Please enter a positive integer." << endl;
        return 1;
    }

    int a[n];

    // Input elements of the array
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    // Perform selection sort
    for (int j = 0; j < n - 1; j++) {
        int iMin = j;
        for (int i = j + 1; i < n; i++) {
            if (a[i] < a[iMin]) {
                iMin = i;
            }
        }
        if (iMin != j) {
            swap(a[j], a[iMin]);
        }
    }

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
