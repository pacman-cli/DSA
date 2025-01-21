/*
 * Coin Change Problem
 * This program implements the greedy approach to solve the coin change problem.
 * Given an amount N and a set of coin denominations, it finds the minimum number
 * of coins needed to make that amount using the available denominations.
 * Note: This greedy approach works only when coin denominations are chosen appropriately
 * (like US cents: 1, 5, 10, 25).
 */

#include <iostream>     // For input/output operations (cin, cout)
#include <vector>       // For using dynamic arrays (vector)
#include <algorithm>    // For using sort and reverse iterators (sort, rbegin, rend)
using namespace std;    // Using standard namespace to avoid std:: prefix

// Function to calculate minimum coins needed for given amount using greedy approach
void makeChange(int N, vector<int>& coins) {
    // Sort coins in descending order (largest to smallest)
    // This ensures we use larger denominations first to minimize total coins
    sort(coins.rbegin(), coins.rend());
    
    // Vector to store pairs of {coin denomination, number of coins used}
    vector<pair<int, int>> coinCount;
    int totalCoins = 0;                   // Keep track of total coins used
    
    // Process each coin denomination from largest to smallest
    for (int coin : coins) {
        if (N >= coin) {                  // If we can use this coin
            int count = N / coin;         // Calculate how many of this coin we need
            N = N % coin;                 // Update remaining amount after using these coins
            coinCount.push_back({coin, count});  // Store the coin and count
            totalCoins += count;          // Update total coins used
        }
    }
    
    // Print the solution - which coins were used and how many
    for (const auto& p : coinCount) {
        if (p.second > 0) {              // Only print denominations that were actually used
            cout << p.first << " cents --- " << p.second << "\n";
        }
    }
    cout << "Total " << totalCoins << " coins\n";  // Print total number of coins used
}

int main() {
    int N;                              // Variable to store the target amount
    cout << "Enter amount in cents: ";
    cin >> N;
    
    int d;                              // Variable to store number of different coin denominations
    cout << "Enter number of coin denominations: ";
    cin >> d;
    
    // Input the available coin denominations
    cout << "Enter " << d << " coin denominations: ";
    vector<int> coins(d);               // Vector to store coin denominations
    for (int i = 0; i < d; i++) {
        cin >> coins[i];
    }
    
    // Call function to solve the coin change problem
    makeChange(N, coins);
    
    return 0;  // End program with success status
}
