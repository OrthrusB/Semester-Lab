#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    int n;

    // Prompt user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Check for valid input
    if (n <= 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    int arr[n];

    // Input elements of the array
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Sort the array
    bubbleSort(arr, n);

    // Display sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
