#include <iostream>
#include <vector>
using namespace std;

#define INF 999999  // Define a large value to represent infinity

// Function to solve the Rod Cutting Problem using Dynamic Programming
int RodCutting(int N, vector<int> prices, int d) {
    int maxPrice[N + 1];  // Array to store the maximum profit for each rod length
    maxPrice[0] = 0;      // Base case: Maximum profit for rod of length 0 is 0

    // Fill the DP array for each rod length from 1 to N
    for (int i = 1; i <= N; i++) {
        maxPrice[i] = -INF;  // Initialize the maximum profit to a very small value
        for (int j = 1; j <= d; j++) {
            // If the current piece of length `j` can fit in the rod of length `i`
            if (j <= i && prices[j] + maxPrice[i - j] > maxPrice[i]) {
                maxPrice[i] = prices[j] + maxPrice[i - j];  // Update the maximum profit
            }
        }
        // Print the maximum profit for the current rod length
        cout << "Rod length " << i << ": Maximum Profit = " << maxPrice[i] << endl;
    }

    // Backtracking to determine the pieces used to achieve the maximum profit
    cout << "Rod pieces used: ";
    for (int i = N; i > 0;) {  // Start with the full rod length
        for (int j = 1; j <= d; j++) {
            // Check if the current piece of length `j` contributes to the maximum profit
            if (j <= i && maxPrice[i] == prices[j] + maxPrice[i - j]) {
                cout << j << " ";  // Print the piece length
                i -= j;            // Reduce the rod length by the piece length
                break;             // Move to the next piece
            }
        }
    }
    cout << endl;
    return maxPrice[N];  // Return the maximum profit for the rod of length N
}

int main() {
    int N = 8;   // Total length of the rod
    int d = 11;  // Number of different rod lengths available
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};  // Prices for each rod length
    // Note: The price for length `0` is set to `0` as a dummy value for 1-based indexing

    // Call the RodCutting function and print the maximum profit
    cout << "Maximum Profit: " << RodCutting(N, prices, d) << endl;
    return 0;
}
