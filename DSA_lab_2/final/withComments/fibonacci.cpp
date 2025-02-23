
#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number using memoization
int Fib(int n, int F[]) {
    // Base cases: Fibonacci of 0 is 0, and Fibonacci of 1 is 1
    if (n == 0 || n == 1) {
        return n;
    }
    // If the Fibonacci value for (n-1) hasn't been computed yet, calculate it
    if (F[n - 1] == -1) {
        F[n - 1] = Fib(n - 1, F);
    }
    // If the Fibonacci value for (n-2) hasn't been computed yet, calculate it
    if (F[n - 2] == -1) {
        F[n - 2] = Fib(n - 2, F);
    }
    // Return the sum of the two previous Fibonacci numbers
    return F[n - 1] + F[n - 2];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;  // Input the value of n for which Fibonacci needs to be calculated

    int F[n];  // Array to store the computed Fibonacci values (memoization)
    for (int i = 0; i < n; i++) {
        F[i] = -1;  // Initialize all entries with -1 (indicating not computed)
    }

    int fib = Fib(n, F);  // Call the Fibonacci function with memoization
    cout << "The " << n << "th Fibonacci number is: " << fib << endl;  // Output the result

    return 0;
}
