// This program demonstrates sorting with greater<> and other STL comparators
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

// Utility function to print array
void printArray(int arr[], int size, string message = "Array:") {
    cout << message << " ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Initialize test array
    int arr[] = {100, 512, 6, 724, 31, 14, 2, 0};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printArray(arr, len, "Original array:");

    // Sort in descending order using greater<int>
    sort(arr, arr + len, greater<int>());
    printArray(arr, len, "Sorted descending:");

    return 0;
}

/* Additional examples using STL comparators:

// Example 1: Using less<> (default behavior)
void lessExample() {
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end(), less<int>());
    // Result: {1, 2, 5, 8, 9}
}

// Example 2: Using greater_equal<>
void greaterEqualExample() {
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end(), greater_equal<int>());
    // Result: {9, 8, 5, 2, 1}
}

// Example 3: Using custom comparator class
class CustomComp {
public:
    bool operator()(int a, int b) {
        // Sort by sum of digits
        return digitSum(a) < digitSum(b);
    }
private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

void customCompExample() {
    vector<int> v = {54, 12, 89, 23, 45};
    sort(v.begin(), v.end(), CustomComp());
    // Sorts by sum of digits
}

// Example 4: Using multiple comparators
template<typename T>
struct MultiComp {
    bool operator()(const T& a, const T& b) const {
        // First compare absolute values
        if (abs(a) != abs(b))
            return abs(a) < abs(b);
        // If equal, compare actual values
        return a < b;
    }
};

void multiCompExample() {
    vector<int> v = {-5, 2, -8, 1, -9};
    sort(v.begin(), v.end(), MultiComp<int>());
    // Sorts by absolute value, then actual value
}

// Example 5: Using lambda with capture
void lambdaWithCaptureExample() {
    int threshold = 5;
    vector<int> v = {3, 8, 2, 7, 4};
    
    sort(v.begin(), v.end(), 
         [threshold](int a, int b) {
             // Numbers > threshold come first
             if ((a > threshold) != (b > threshold))
                 return a > threshold;
             return a < b;
         });
}

// Example 6: Sorting pairs with multiple criteria
void sortPairsExample() {
    vector<pair<int,int>> v = {{1,5}, {2,3}, {1,2}};
    
    // Sort by first element, then second
    sort(v.begin(), v.end(), 
         [](const pair<int,int>& a, const pair<int,int>& b) {
             if (a.first != b.first)
                 return a.first < b.first;
             return a.second < b.second;
         });
}

Usage examples:
lessExample();              // Default ascending sort
greaterEqualExample();      // Descending sort
customCompExample();        // Sort by digit sum
multiCompExample();         // Sort by absolute value
lambdaWithCaptureExample(); // Sort with threshold
sortPairsExample();         // Sort pairs
*/