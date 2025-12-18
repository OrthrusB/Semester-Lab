#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int hole = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than hole, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > hole) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = hole;
    }
}

int main() {
    int n;
    cout << "Enter the size of n: ";
    cin >> n;

    // Error handling for negative array size
    if (n <= 0) {
        cerr << "Error: Size of array should be a positive integer." << endl;
        return 1; // Exiting with error
    }

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Sort the array using insertion sort
    insertionSort(arr, n);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0; // Exiting successfully
}
