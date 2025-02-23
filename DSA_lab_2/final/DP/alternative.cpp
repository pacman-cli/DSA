#include <climits>  // For INT_MAX
#include <iostream>
#include <vector>

using namespace std;

int minCostToMakeRope(int M, vector<int> &C, int X) {
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;  // Base case: 0 cost for making 0-length rope

    // Bottom-up DP approach
    for (int m = 1; m <= M; m++) {
        for (int i = 0; i < C.size(); i++) {
            if (C[i] <= m && dp[m - C[i]] != INT_MAX) {
                dp[m] = min(dp[m], dp[m - C[i]] + X);
            }
        }
    }

    return (dp[M] == INT_MAX) ? -1 : dp[M];  // Return -1 if it's not possible to form M meters
}

int main() {
    int M = 10;                 // Total length needed
    vector<int> C = {1, 3, 5};  // Available rope lengths
    int X = 2;                  // Cost to join two ropes

    int result = minCostToMakeRope(M, C, X);
    if (result == -1)
        cout << "It's not possible to create " << M << " meter long rope." << endl;
    else
        cout << "Minimum cost to make " << M << " meter long rope: " << result << endl;

    return 0;
}
