// This program demonstrates sorting pairs based on ratios
#include <iostream>
using namespace std;

// Structure to hold a pair of integers
struct Pair {
    int a, b;  // a is denominator, b is numerator
};

// Comparison function that sorts based on b/a ratio
bool comp2(Pair p1, Pair p2) {
    // Compare ratios of b/a for each pair
    return (double)p1.b / p1.a < (double)p2.b / p2.a;
}

int main() {
    // Test array of pairs
    Pair arr[] = {{5, 100}, {3, 9}, {3, 12}, {1, 6}, {5, 5}, {8, 16}};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Sort array based on b/a ratio
    sort(arr, arr + len, comp2);

    // Print sorted array with ratios
    for (int i = 0; i < len; i++) {
        cout << "a:" << arr[i].a << " "
             << "b:" << arr[i].b << " "
             << "ratio:" << fixed << setprecision(2) << (double)arr[i].b / arr[i].a << " | ";
    }
    cout << endl;
    return 0;
}

/* Additional comparison function examples:

// Sort by ratio in descending order
bool compRatioDesc(Pair p1, Pair p2) {
    return (double)p1.b / p1.a > (double)p2.b / p2.a;
}

// Sort by absolute difference between a and b
bool compDiff(Pair p1, Pair p2) {
    return abs(p1.b - p1.a) < abs(p2.b - p2.a);
}

// Sort by product of a and b
bool compProduct(Pair p1, Pair p2) {
    return p1.a * p1.b < p2.a * p2.b;
}

Example usage:
Pair arr[] = {{2, 4}, {3, 9}, {4, 8}, {5, 10}};
sort(arr, arr + 4, compRatioDesc);  // Sort by ratio descending
sort(arr, arr + 4, compDiff);       // Sort by absolute difference
sort(arr, arr + 4, compProduct);    // Sort by product
*/
