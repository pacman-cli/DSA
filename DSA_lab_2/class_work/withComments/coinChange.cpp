#include <iostream>
#include <vector>
using namespace std;

#define INF 999999  // Define a large value to represent infinity

// Function to solve the Coin Change Problem
int CoinChange(int M, vector<int> coins, int d) {
    int mnc[M + 1];  // Array to store the minimum number of coins needed for each amount
    mnc[0] = 0;      // Base case: 0 coins are needed to make amount 0

    // Fill the DP array
    for (int m = 1; m <= M; m++) {
        mnc[m] = INF;  // Initialize the current amount with infinity
        for (int i = 0; i < d; i++) {
            // Check if the current coin can be used
            if (coins[i] <= m && mnc[m - coins[i]] + 1 < mnc[m]) {
                mnc[m] = mnc[m - coins[i]] + 1;  // Update the minimum coins required
            }
        }
        cout << m << " " << mnc[m] << endl;  // Debug output to show the DP table being filled
    }

    // Printing the minimum number of coins needed
    cout << "Total number of coins needed: " << mnc[M] << endl;

    // Backtrack to find which coins were used
    cout << "Coins: ";
    for (int m = M; m > 0;) {
        for (int i = 0; i < d; i++) {
            if (mnc[m - coins[i]] + 1 == mnc[m]) {
                cout << coins[i] << " ";  // Print the coin used
                m -= coins[i];            // Reduce the amount by the coin value
                break;
            }
        }
    }

    return mnc[M];  // Return the minimum number of coins required
}

int main() {
    int M, d, x;
    cin >> M >> d;  // Input the target amount and the number of denominations
    vector<int> coins;
    for (int i = 1; i <= d; i++) {
        cin >> x;  // Input the coin denominations
        coins.push_back(x);
    }
    int totalcoins = CoinChange(M, coins, d);  // Call the function
    return 0;
}
// example
// M=30
// coins ={25,10,1}; here d = 3
