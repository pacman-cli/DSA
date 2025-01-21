
#include <iostream>
#include <vector>
using namespace std;
#define INF 999999

int RodCutting(int N, vector<int> prices, int d) {
    vector<int> maxPrice(N + 1, -INF);  // Max price for each rod length
    maxPrice[0] = 0;                    // Base case: no price for rod of length 0

    // Dynamic Programming: Calculate max price for each rod length
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= d; j++) {
            if (j <= i && maxPrice[i - j] + prices[j] > maxPrice[i]) {
                maxPrice[i] = maxPrice[i - j] + prices[j];
            }
        }
        cout << "Length: " << i << ", Max Price: " << maxPrice[i] << endl;
    }

    // Backtracking to find the cuts used
    cout << "Cuts used: ";
    int length = N;
    while (length > 0) {
        for (int j = 1; j <= d; j++) {
            if (j <= length && maxPrice[length] == prices[j] + maxPrice[length - j]) {
                cout << j << " ";
                length -= j;
                break;  // Move to the next remaining length
            }
        }
    }
    cout << endl;

    return maxPrice[N];
}

int main() {
    int N = 8;                                                     // Length of the rod
    int d = 11;                                                    // Number of available prices
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};  // Prices for each length

    cout << "Maximum Obtainable Price: " << RodCutting(N, prices, d) << endl;
    return 0;
}
