#include <iostream>
#include <vector>
#define INF 99999;
using namespace std;
int CoinChange(int M, vector<int> coins, int d) {
    int mnc[M + 1];
    mnc[0] = 0;

    for (int m = 1; m <= M; m++) {
        mnc[m] = INF;
        for (int i = 0; i < d; i++) {
            if (coins[i] <= m && mnc[m - coins[i]] + 1 < mnc[m]) {
                mnc[m] = mnc[m - coins[i]] + 1;
            }
        }
        cout << m << " " << mnc[m] << endl;
    }
    cout << mnc[M] << endl;  // coins needed
                             //  backtrack
    cout << "Coins:";
    for (int m = M; m > 0;) {
        for (int i = 1; i <= d; i++) {
            if (mnc[m - coins[i]] + 1 == mnc[i]) {
                cout << coins[i] << " ";  // coins used
                m -= coins[i];
                break;
            }
        }
    }
    return mnc[M];
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
