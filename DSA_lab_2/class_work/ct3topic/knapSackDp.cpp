#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W

int KnapsackBottomUp(int val[], int wt[], int n, int W) {
    int table[100][100];
    for (int w = 0; w <= W; w++) {
        table[0][w] = 0;
    }

    for (int i = 0; i <= n; i++) {
        table[i][0] = 0;
        for (int w = 0; w <= W; w++) {
            if (wt[i] <= w) {
                table[i][w] = max(val[i] + table[i - 1][w - wt[i]], table[i - 1][w]);
                // if (val[i] + table[i - 1][w - wt[i]] > table[i - 1][w])
                //     table[i][w] = val[i] + table[i - 1][w - wt[i]];
                // else
                //     table[i][w] = table[i - 1][w];
            } else
                table[i][w] = table[i - 1][w];
        }
    }

    int i = n;
    int w = W;
    vector<int> taken_items;
    while (i >= 0 && w >= 0) {
        if (table[i][w] == val[i] + table[i - 1][w - wt[i]]) {
            taken_items.push_back(i);
            w = w - wt[i];
            i--;
        } else
            i--;
    }

    for (int j = taken_items.size() - 1; j >= 0; j--) cout << taken_items[j] << " ";
    cout << endl;

    return table[n][W];
}

// Driver Code
int main() {
    int profit[] = {0, 10, 15, 40};
    int weight[] = {0, 1, 2, 3};
    int W = 6;
    int n = 3;  // Number of Items

    // cout << knapSack(W, weight, profit, n);
    cout << KnapsackBottomUp(profit, weight, n, W) << endl;

    return 0;
}
