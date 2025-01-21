#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    // Calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the subarrays
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;     // Initial index of first subarray
    int j = 0;     // Initial index of second subarray
    int k = left;  // Initial index of merged array

    // Compare and merge elements from both subarrays
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray[] if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray[] if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Main mergeSort function that sorts arr[left..right] using merge()
void mergeSort(vector<int>& arr, int left, int right) {
    // Base case: return when size is 1 or less
    if (left >= right) return;

    // Find the middle point to divide array into two halves
    int mid = left + (right - left) / 2;

    // Recursively sort first and second halves
    mergeSort(arr, left, mid);       // Sort left half
    mergeSort(arr, mid + 1, right);  // Sort right half

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// Main function to demonstrate the merge sort
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    // Perform merge sort
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
