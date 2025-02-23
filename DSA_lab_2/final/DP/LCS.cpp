#include <iostream>  // Standard Input/Output Library
#include <vector>    // For using vector (dynamic array)
using namespace std;

// Function to compute the DP table for LCS
vector<vector<int>> computeLCS(const string &X, const string &Y) {
    int m = X.length(), n = Y.length();

    // Create a (m+1) x (n+1) DP table initialized with 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table using a bottom-up approach
    for (int i = 1; i <= m; i++) {      // Iterate through string X
        for (int j = 1; j <= n; j++) {  // Iterate through string Y
            if (X[i - 1] == Y[j - 1]) {
                // If characters match, extend the LCS from previous diagonal cell
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Otherwise, take the maximum from top or left cell
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;  // Return the filled DP table
}

// Function to reconstruct LCS from DP table
string getLCS(const string &X, const string &Y, const vector<vector<int>> &dp) {
    int i = X.length(), j = Y.length();
    string lcs;  // String to store LCS result

    // Backtracking to find the LCS string
    while (i > 0 && j > 0) {  // Continue until one string is exhausted
        if (X[i - 1] == Y[j - 1]) {
            // If characters match, add to LCS and move diagonally
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            // Move upwards if previous row has a larger LCS value
            i--;
        } else {
            // Move left if previous column has a larger LCS value
            j--;
        }
    }

    return lcs;  // Return the constructed LCS string
}

int main() {
    string X = "ABCBDAB";  // Input string 1
    string Y = "BDCABA";   // Input string 2

    // Compute the DP table for LCS
    vector<vector<int>> dp = computeLCS(X, Y);

    // Retrieve the LCS from the computed DP table
    string lcs = getLCS(X, Y, dp);

    // Output the final results
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of LCS: " << dp[X.length()][Y.length()] << endl;

    return 0;  // End of program
}
