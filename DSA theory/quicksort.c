#include <stdio.h>

void quickSort(int arr[], int low, int high);
int medianPivot(int arr[], int low, int high);
int partition(int arr[], int low, int high, int pivot);
void swap(int *a, int *b);

int main() {
    // Initial array
    int arr[] = {20, 33, 41, 55, 56, 60, 61, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Quick sort in descending order using median pivot
    quickSort(arr, 0, n - 1);
    
    // Print sorted array
    printf("\nSorted Array in Descending Order: \n");
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Choose the median pivot
        int pivotIndex = medianPivot(arr, low, high);
        int pivot = arr[pivotIndex];

        // Partition the array using the median pivot
        int pi = partition(arr, low, high, pivot);
        
        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);  // Left subarray
        quickSort(arr, pi + 1, high); // Right subarray
    }
}

// Function to find the median of the first, middle, and last elements as pivot
int medianPivot(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    printf("\nmid: %d\n", mid);
    
    // Sorting the low, mid, high values to find the median
    if (arr[low] > arr[mid]) {
        swap(&arr[low], &arr[mid]);
    }
    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }
    if (arr[mid] > arr[high]) {
        swap(&arr[mid], &arr[high]);
    }
    
    // Return the index of the median element
    return mid;
}

// Partition function to sort the array around a pivot
int partition(int arr[], int low, int high, int pivot) {
    int i = low;
    int j = high;
    
    printf("\nPartitioning with Pivot: %d\n", pivot);
    
    while (i <= j) {
        // Move i to the right while arr[i] is greater than the pivot (for descending order)
        while (arr[i] > pivot) {
            i++;
        }
        // Move j to the left while arr[j] is less than the pivot
        while (arr[j] < pivot) {
            j--;
        }
        // If i is less than j, swap arr[i] and arr[j]
        if (i <= j) {
            printf("Swapping: arr[%d] = %d and arr[%d] = %d\n", i, arr[i], j, arr[j]);
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    // Return the partition index
    return i;
}

// Utility function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}