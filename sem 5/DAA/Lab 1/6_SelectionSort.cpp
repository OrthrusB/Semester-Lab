#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &steps) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            steps++; // Count comparison
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex
            }
        }
        // Swap the smallest element with the current element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n, steps = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n, steps);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSteps required: " << steps << endl;
    return 0;
}
 