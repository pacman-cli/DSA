// This program demonstrates various array sorting techniques in C++
#include <iostream>
#include <cstdio>
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

    // Sort array in ascending order
    sort(arr, arr + len);
    printArray(arr, len, "Sorted ascending:");

    // Sort array in descending order
    sort(arr, arr + len, greater<int>());
    printArray(arr, len, "Sorted descending:");

    return 0;
}

/* Additional sorting examples:

// Example 1: Sort part of array
void partialSort() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int len = 6;
    
    // Sort only first 4 elements
    sort(arr, arr + 4);
    // Result: {1, 2, 5, 8, 9, 3}
}

// Example 2: Custom comparison function
bool customComp(int a, int b) {
    // Sort based on last digit
    return (a % 10) < (b % 10);
}

void customSort() {
    int arr[] = {23, 51, 14, 19, 8, 5};
    sort(arr, arr + 6, customComp);
    // Sorts by last digit: 51, 23, 14, 5, 8, 19
}

// Example 3: Sort array of strings
void sortStrings() {
    string arr[] = {"banana", "apple", "cherry"};
    sort(arr, arr + 3);
    // Result: {"apple", "banana", "cherry"}
}

// Example 4: Sort in reverse order using reverse iterators
void reverseSort() {
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.rbegin(), v.rend());
    // Result: {9, 8, 5, 2, 1}
}

// Example 5: Stable sort (maintains relative order of equal elements)
struct Person {
    string name;
    int age;
};

bool compareAge(Person p1, Person p2) {
    return p1.age < p2.age;
}

void stableSortExample() {
    vector<Person> people = {
        {"Alice", 25},
        {"Bob", 20},
        {"Charlie", 25}
    };
    stable_sort(people.begin(), people.end(), compareAge);
    // People with same age maintain relative order
}

// Example 6: Sort with lambda function
void lambdaSort() {
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end(), 
         [](int a, int b) { return abs(a) < abs(b); });
    // Sorts by absolute value
}

// Example 7: Partial sort with nth_element
void nthElementSort() {
    vector<int> v = {5, 2, 8, 1, 9, 3, 7};
    // Put 3rd element in its sorted position
    nth_element(v.begin(), v.begin() + 2, v.end());
    // Elements before 3rd position are smaller
    // Elements after are larger
}

Usage examples:
int arr[] = {5, 2, 8, 1, 9, 3};
partialSort();           // Sort part of array
customSort();            // Sort with custom comparison
sortStrings();           // Sort strings
reverseSort();           // Sort in reverse
stableSortExample();     // Stable sort
lambdaSort();            // Sort with lambda
nthElementSort();        // Partial sort
*/
