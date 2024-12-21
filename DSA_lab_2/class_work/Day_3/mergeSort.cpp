// Implementation of Merge Sort algorithm using divide and conquer approach
#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray
    
    // Create temporary arrays to hold the subarrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // Copy data to temporary arrays leftArr[] and rightArr[]
    for(int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
        
    // Initialize indices for merging
    int i = 0;      // Initial index of left subarray
    int j = 0;      // Initial index of right subarray
    int k = left;   // Initial index of merged array
    
    // Merge the temp arrays back into arr[left..right]
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            // If element from left array is smaller
            arr[k] = leftArr[i];
            i++;
        } else {
            // If element from right array is smaller
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr[] if any
    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr[] if any
    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Main mergeSort function that sorts arr[left..right] using merge()
void mergeSort(int arr[], int left, int right) {
    // Base case: return if array has less than 2 elements
    if(left >= right)
        return;
        
    // Find middle point to divide array into two halves
    int mid = left + (right - left) / 2;
    
    // Recursively sort first and second halves
    mergeSort(arr, left, mid);      // Sort left half
    mergeSort(arr, mid + 1, right); // Sort right half
    
    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Test array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    // Perform merge sort
    mergeSort(arr, 0, n-1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

/* How Merge Sort Works:

1. Divide Step:
   - The array is recursively divided into two halves until each subarray contains 1 element
   - This is handled by the mergeSort() function
   
2. Conquer Step:
   - The merge() function combines two sorted subarrays into one sorted array
   - It creates temporary arrays and merges them back maintaining sorted order
   
3. Time Complexity:
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   
4. Space Complexity:
   - O(n) for temporary arrays during merging
   
5. Advantages:
   - Stable sorting algorithm
   - Guaranteed O(n log n) time complexity
   - Works well for linked lists
   
6. Disadvantages:
   - Requires extra space
   - Not in-place sorting algorithm
   
Example of division process for array [64, 34, 25, 12]:
                [64, 34, 25, 12]
               /              \
        [64, 34]            [25, 12]
        /      \            /       \
     [64]     [34]       [25]     [12]
        \      /            \       /
        [34, 64]            [12, 25]
               \              /
            [12, 25, 34, 64]
*/