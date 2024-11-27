#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int findLengthOfShortestSubarray(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Find the longest non-decreasing prefix
    int i = 0;
    while (i < n - 1 && arr[i] <= arr[i + 1]) {
      i++;
    }

    // If the entire array is sorted
    if (i == n - 1) {
      return 0;
    }

    // Step 2: Find the longest non-decreasing suffix
    int j = n - 1;
    while (j > 0 && arr[j - 1] <= arr[j]) {
      j--;
    }

    // Step 3: Calculate the minimum length to remove
    int minLength = min(n - i - 1, j); // Remove either suffix or prefix

    // Step 4: Merge prefix and suffix
    int left = 0, right = j;
    while (left <= i && right < n) {
      if (arr[left] <= arr[right]) {
        minLength = min(minLength, right - left - 1);
        left++;
      } else {
        right++;
      }
    }

    return minLength;
  }
};

// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Solution {
// public:
//   int findLengthOfShortestSubarray(vector<int> &arr) {
//     int n = arr.size();
//
//     // Step 1: Find the longest non-decreasing prefix
//     int i = 0;
//     while (i < n - 1 && arr[i] <= arr[i + 1]) {
//       i++;
//     }
//
//     // If the entire array is sorted
//     if (i == n - 1) {
//       return 0;
//     }
//
//     // Step 2: Find the longest non-decreasing suffix
//     int j = n - 1;
//     while (j > 0 && arr[j - 1] <= arr[j]) {
//       j--;
//     }
//
//     // Step 3: Calculate the minimum length to remove
//     int minLength = min(n - i - 1, j); // Remove either suffix or prefix
//
//     // Step 4: Merge prefix and suffix
//     int left = 0, right = j;
//     while (left <= i && right < n) {
//       if (arr[left] <= arr[right]) {
//         minLength = min(minLength, right - left - 1);
//         left++;
//       } else {
//         right++;
//       }
//     }
//
//     return minLength;
//   }
// };
//
// int main() {
//   Solution solution;
//   // Test cases
//   vector<int> arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
//   vector<int> arr2 = {5, 4, 3, 2, 1};
//   vector<int> arr3 = {1, 2, 3};
//
//   cout << "Test Case 1: " << solution.findLengthOfShortestSubarray(arr1)
//        << endl; // Output: 3
//   cout << "Test Case 2: " << solution.findLengthOfShortestSubarray(arr2)
//        << endl; // Output: 4
//   cout << "Test Case 3: " << solution.findLengthOfShortestSubarray(arr3)
//        << endl; // Output: 0
//
//   return 0;
// }
