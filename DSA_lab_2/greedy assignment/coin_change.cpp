#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void makeChange(int N, vector<int>& coins) {
    sort(coins.rbegin(), coins.rend());

    vector<pair<int, int>> coinCount;
    int totalCoins = 0;
    for (int coin : coins) {
        if (N >= coin) {
            int count = N / coin;
            N = N % coin;
            coinCount.push_back({coin, count});
            totalCoins += count;
        }
    }

    for (const auto& p : coinCount) {
        if (p.second > 0) {
            cout << p.first << " cents --- " << p.second << "\n";
        }
    }
    cout << "Total " << totalCoins << " coins\n";
}

int main() {
    int N;
    cout << "Enter amount in cents: ";
    cin >> N;

    int d;
    cout << "Enter number of coin denominations: ";
    cin >> d;

    cout << "Enter " << d << " coin denominations: ";
    vector<int> coins(d);
    for (int i = 0; i < d; i++) {
        cin >> coins[i];
    }

    makeChange(N, coins);

    return 0;
}
