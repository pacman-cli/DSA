#include <iostream>
#include <vector>
using namespace std;

int RodCutting(int N, vector<int> prices, int d) {
    vector<int> maxPrice(N + 1, 0);  // Initialize with 0
    maxPrice[0] = 0;

    for (int i = 1; i <= N; i++) {
        int currMax = -1;  // Initialize with -1 for maximization
        for (int j = 1; j <= d && j <= i; j++) {
            if (j < prices.size()) {
                currMax = max(currMax, prices[j] + maxPrice[i - j]);
            }
        }
        maxPrice[i] = currMax;
        cout << "Length:" << i << " Max Price:" << maxPrice[i] << endl;
    }

    // Print the cuts used
    cout << "Cuts used: ";
    for (int i = N; i > 0;) {
        for (int j = 1; j <= d && j <= i; j++) {
            if (j < prices.size() && maxPrice[i] == prices[j] + maxPrice[i - j]) {
                cout << j << " ";
                i -= j;
                break;
            }
        }
    }
    cout << endl;
    
    return maxPrice[N];
}

int main() {
    int N = 8;
    int d = 11;
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << "Maximum value: " << RodCutting(N, prices, d) << endl;
    return 0;
}
