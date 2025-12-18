#include <iostream>

using namespace std;

int steps = 0;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Pivot element
    int i = low;
    int j = high;

    while (i < j) {
        while (i < high && arr[i] <= pivot) {
            i++;
            steps++;
        }
        while (j > low && arr[j] > pivot) {
            j--;
            steps++;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]); // Place pivot in correct position
     steps++; 
    return j;
}

// Randomized partition
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // Random index
    swap(arr[low], arr[randomIndex]); 
   
    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
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
    
    // Sort the array using randomized quick sort
    randomizedQuickSort(arr, 0, n - 1);
    
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