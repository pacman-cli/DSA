#include <iostream>
#include <vector>  // To use the vector data structure
using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem using the Bottom-Up approach
int KnapsackBottomUp(int val[], int wt[], int n, int W) {
    int table[100][100];  // DP table to store the maximum value for each subproblem

    // Initialize the base cases:
    // If the capacity (W) is 0, the maximum value is 0
    for (int w = 0; w <= W; w++) {
        table[0][w] = 0;
    }

    // If there are 0 items, the maximum value for any capacity is 0
    for (int i = 0; i <= n; i++) {
        table[i][0] = 0;
    }

    // Build the DP table iteratively
    for (int i = 1; i <= n; i++) {      // Iterate through all items
        for (int w = 1; w <= W; w++) {  // Iterate through all capacities
            if (wt[i] <= w) {  // If the current item's weight is less than or equal to the capacity
                // Include the current item if it improves the maximum value
                table[i][w] = max(val[i] + table[i - 1][w - wt[i]], table[i - 1][w]);
            } else {
                // Exclude the current item
                table[i][w] = table[i - 1][w];
            }
        }
    }

    // Backtracking to find the items included in the knapsack
    int i = n;                // Start from the last item
    int w = W;                // Start from the full capacity
    vector<int> taken_items;  // To store the indices of items included in the knapsack

    while (i > 0 && w > 0) {
        // If the current item's value was included in the optimal solution
        if (table[i][w] == val[i] + table[i - 1][w - wt[i]]) {
            taken_items.push_back(i);  // Add the current item to the solution
            w = w - wt[i];             // Reduce the remaining capacity
        }
        i--;  // Move to the previous item
    }

    // Print the indices of the items included in the knapsack
    for (int j = taken_items.size() - 1; j >= 0; j--) {
        cout << taken_items[j] << " ";
    }
    cout << endl;

    return table[n][W];  // Return the maximum value that can be achieved
}

// Driver Code
int main() {
    int profit[] = {0, 10, 15,
                    40};          // Values of the items (1-based indexing, so 0 is a dummy value)
    int weight[] = {0, 1, 2, 3};  // Weights of the items (1-based indexing, so 0 is a dummy value)
    int W = 6;                    // Capacity of the knapsack
    int n = 3;                    // Number of items

    // Call the KnapsackBottomUp function and print the maximum profit
    cout << "Maximum Profit: " << KnapsackBottomUp(profit, weight, n, W) << endl;

    return 0;
}
