// This program demonstrates custom comparison function with sort
#include <iostream>
using namespace std;
struct Pair {
    int a, b;  // 'a' is first element, 'b' is second element
};

// Custom comparison function that compares two Pair objects
// Returns true if first pair should come before second pair
bool comp(Pair p1, Pair p2) {
    printf("p1.b:%d p2.b:%d\n", p1.b, p2.b);  // Debug print
    return p1.b < p2.b;                       // Sort based on 'b' values ascending
}

int main() {
    // Initialize array of Pairs with test data
    Pair arr[] = {{5, 100}, {3, 9}, {3, 12}, {1, 6}, {5, 5}, {8, 16}};
    int len = sizeof(arr) / sizeof(arr[0]);  // Calculate array length

    // Sort array using custom comparison function
    sort(arr, arr + len, comp);

    // Print sorted array
    for (int i = 0; i < len; i++) {
        cout << "a:" << arr[i].a << " " << " b:" << arr[i].b << " | ";
    }
    cout << endl;
    return 0;
}

// Additional comparison function examples:
/*
// Sort by 'a' values:
bool compByA(Pair p1, Pair p2) {
    return p1.a < p2.a;
}

// Sort by sum of a and b:
bool compBySum(Pair p1, Pair p2) {
    return (p1.a + p1.b) < (p2.a + p2.b);
}

// Sort by 'b' descending:
bool compDesc(Pair p1, Pair p2) {
    return p1.b > p2.b;
}
*/
