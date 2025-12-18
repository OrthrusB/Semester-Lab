#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[], int low, int high, int &steps) {
    int pivot = A[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        steps++;
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

void quicksort(int A[], int low, int high, int &steps) {
    if (low < high) {
        int pi = partition(A, low, high, steps);
        quicksort(A, low, pi - 1, steps);
        quicksort(A, pi + 1, high, steps);
    }
}

int main() {
    int n, steps = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *A = new int[n];  // Dynamic allocation

    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    quicksort(A, 0, n - 1, steps);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {  // Fixed the loop condition
        cout << A[i] << " ";
    }

    cout << "\nSteps taken: " << steps << endl;

    delete[] A;  // Free dynamically allocated memory
    return 0;
}
