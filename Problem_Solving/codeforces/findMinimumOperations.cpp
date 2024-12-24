#include <iostream>
using namespace std;

// Function to count the minimum operations to make n zero
int minOperations(int n, int k) {
  int operations = 0;

  // Edge case for k == 1, since we can only subtract 1 (k^0 = 1)
  if (k == 1) {
    return n; // We need exactly n operations
  }

  // Continue subtracting the largest power of k
  while (n > 0) {
    // Find the largest power of k that is <= n
    long long power = 1;
    while (power * k <= n) {
      power *= k;
    }
    // Subtract that power from n
    n -= power;
    // Increment the operation count
    operations++;
  }

  return operations;
}

int main() {
  int t;
  cin >> t; // Number of test cases

  // Process each test case
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << minOperations(n, k) << endl;
  }

  return 0;
}
