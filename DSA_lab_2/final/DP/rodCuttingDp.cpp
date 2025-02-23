#include <iostream>
#include <vector>
using namespace std;
#define INF -999999  // Changed INF to a negative value

int RodCutting(int N, vector<int> prices, int d) {
    int maxPrice[N + 1];
    maxPrice[0] = 0;  // No rod -> No price

    // Initialize maxPrice array
    for (int i = 1; i <= N; i++) {
        maxPrice[i] = INF;
        for (int j = 1; j <= min(d, i); j++) {  // j <= min(d, i) to prevent out-of-bound access
            maxPrice[i] = max(maxPrice[i], prices[j] + maxPrice[i - j]);
        }
        cout << "Length: " << i << ", Max Price: " << maxPrice[i] << endl;
    }

    // Backtracking to find rod cuts
    cout << "Rod pieces used: ";
    for (int i = N; i > 0;) {
        for (int j = 1; j <= min(d, i); j++) {
            if (maxPrice[i] == prices[j] + maxPrice[i - j]) {
                cout << j << " ";  // Output piece size
                i -= j;            // Reduce length
                break;             // Stop and check next
            }
        }
    }
    cout << endl;

    return maxPrice[N];  // Maximum obtainable price
}

int main() {
    int N = 8;
    int d = 10;  // Changed to match the size of the prices array
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};  // Prices (1-based indexing)

    cout << "Maximum Price: " << RodCutting(N, prices, d) << endl;
    return 0;
}
