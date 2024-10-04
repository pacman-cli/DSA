#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t; // Number of test cases

  // Declare an array to store results for each test case
  int results[t];

  // Process each test case
  for (int i = 0; i < t; i++) {
    long long n, k;
    cin >> n >> k;

    int operations = 0;

    // Special case when k == 1
    if (k == 1) {
      operations = n; // We need exactly n operations to reduce it to 0
    } else {
      // General case when k > 1
      while (n > 0) {
        // If remainder of n / k is non-zero, count it as an operation
        operations += n % k; // Count non-zero remainders as operations
        // Reduce n by dividing it by k
        n /= k;
        // Add one operation for each division step
        operations++;
      }
      // The final division brings n to 0, so no need to count the last
      // operation
      operations--;
    }

    // Store the result in the array
    results[i] = operations;
  }

  // Output all results
  for (int i = 0; i < t; i++) {
    cout << results[i] << endl;
  }

  return 0;
}
