#include <iostream>
using namespace std;

int steps = 0; // Counter to track the number of steps

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // Left child index
    int r = 2 * i + 2; // Right child index

    if (l < n) {
        steps++; 
        if (arr[l] > arr[largest])
            largest = l;
    }

  
    if (r < n) {
        steps++;
        if (arr[r] > arr[largest])
            largest = r;
    }

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap counts as a step
        steps++; // Increment step count for swapping
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        steps++;
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Heapify the reduced heap
    }
}

int main() {
    int n;
    cout << "Enter the size of n: ";
    cin >> n;
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Sort the array using heap sort
    heapSort(arr, n);

    // Display the sorted array
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display the number of steps
    cout << "Number of steps used: " << steps << endl;

    return 0;
}