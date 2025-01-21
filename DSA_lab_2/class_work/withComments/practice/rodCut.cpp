#include <iostream>
using namespace std;
#define INF 99999
int rodCutting(int N, vector<int> prices, int d) {
    vector<int> maxPrice(N + 1, -INF);
    maxPrice[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= d; j++) {
            if (j <= i && prices[j] + maxPrice[i - j] > maxPrice[i]) {
                maxPrice[i] = prices[j] + maxPrice[i - j];
            }
        }
        cout << "Length:" << i << "Maxprice" << maxPrice[i] << endl;
    }
    cout << "Cuts used:";
    int length = N;
    while (length > 0) {
        for (int j = 0; j < d; j++) {
            if (j <= length && maxPrice[length - j] + prices[j] == maxPrice[length]) {
                cout << j << " ";
                length -= j;
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
    cout << "Maximum obtainable price:" << rodCutting(N, prices, d);
    return 0;
}
