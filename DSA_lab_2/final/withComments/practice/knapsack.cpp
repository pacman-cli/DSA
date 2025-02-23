#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
int KnapsackBottomUp(int val[], int wt[], int n, int W) {
    int table[100][100];
    for (int i = 0; i < W; i++) {
        table[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i] <= w) {
                table[i][w] = max(table[i - 1][w], val[i] + table[i - 1][w - wt[i]]);
            } else {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    int i = n;
    int w = W;
    vector<int> taken_items;
    while (i >= 0 && w >= 0) {
        if (table[i][w] == val[i] + table[i - 1][w - wt[i]]) {
            taken_items.push_back(i);
            w -= wt[i];
            i--;
        } else {
            i--;
        }
    }
    for (int i = taken_items.size() - 1; i >= 0; i--) {
        cout << taken_items[i] << " ";
    }
    cout << endl;
    return table[n][W];
}
int main() {
    int profit[] = {0, 10, 15, 40};
    int weight[] = {0, 1, 2, 3};
    int W = 6;
    int n = 3;  // Number of Items

    // cout << knapSack(W, weight, profit, n);
    cout << KnapsackBottomUp(profit, weight, n, W) << endl;

    return 0;
}
