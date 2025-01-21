#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int KnapsackBottomUp(int val[], int wt[], int n, int W) {
    int table[100][100];

    // Initialize table for the base cases
    for (int w = 0; w <= W; w++) {
        table[0][w] = 0;  // No items, no value
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i] <= w) {
                table[i][w] = max(val[i] + table[i - 1][w - wt[i]], table[i - 1][w]);
            } else {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    // Traceback to find the items included in the knapsack
    int i = n;
    int w = W;
    vector<int> taken_items;

    while (i > 0 && w > 0) {
        if (table[i][w] != table[i - 1][w]) {
            taken_items.push_back(i);
            w -= wt[i];
        }
        i--;
    }

    // Output the indices of items included
    for (int j = taken_items.size() - 1; j >= 0; j--) {
        cout << taken_items[j] << " ";
    }
    cout << endl;

    return table[n][W];
}

// Driver Code
int main() {
    int profit[] = {0, 10, 15, 40};  // 0 is a placeholder for 1-based index
    int weight[] = {0, 1, 2, 3};     // 0 is a placeholder for 1-based index
    int W = 4;
    int n = 3;  // Number of Items

    cout << KnapsackBottomUp(profit, weight, n, W) << endl;

    return 0;
}
