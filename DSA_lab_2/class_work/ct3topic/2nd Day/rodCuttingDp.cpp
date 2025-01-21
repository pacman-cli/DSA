#include <iostream>
using namespace std;
#define INF 999999
int RodCutting(int N, vector<int> prices, int d) {
    int maxPrice[N + 1];
    maxPrice[0] = 0;

    for (int i = 1; i <= N; i++) {
        maxPrice[i] = INF;
        for (int j = 1; j <= d; j++) {
            // if (j<=i && prices[j]+maxPrice[i-j]>maxPrice[i])
            // {
            //     maxPrice[i] = prices[j]+maxPrice[i-j];
            // }
            if (j <= i) {  // Only use cuts smaller or equal to the current rod length
                maxPrice[i] = max(maxPrice[i], prices[j] + maxPrice[i - j]);
            }
        }
        cout << "Length:" << i << " " << "Max Price:" << maxPrice[i] << endl;
    }

    // Printing the coins

    for (int i = N; i > 0;) {
        for (int j = 1; j <= d; j++) {
            // if (maxPrice[i] ==prices[j]+maxPrice[i-j])
            // {
            //     cout << j << " ";
            //     i-=j;
            // }
            if (j <= i && maxPrice[i] == prices[j] + maxPrice[i - j]) {
                cout << j << " ";  // Output the cut size
                i -= j;            // Reduce the length
                break;             // Break and check again for remaining length
            }
        }
    }
    cout << endl;
    return maxPrice[N];
}

int main() {
    int N = 8;
    int d = 11, x;
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << RodCutting(N, prices, d) << endl;
    return 0;
}
