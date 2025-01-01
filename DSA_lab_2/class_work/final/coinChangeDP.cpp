#include<bits/stdc++.h>
using namespace std;

#define INF 999999

int CoinChange(int M, vector<int> coins, int d)
{
    int mnc[M+1];
    mnc[0] = 0;

    for (int m = 1; m <= M; m++)
    {
        mnc[m] = INF;
        for (int i = 0; i < d; i++)
        {
            if (coins[i] <= m && mnc[m - coins[i]] + 1 < mnc[m])
            {
                mnc[m] = mnc[m - coins[i]] + 1;
            }
        }
        cout << m << " " << mnc[m] << endl;
    }

    // Printing the coins
    cout << "Total number of coins needed: " << mnc[M] << endl;
    cout << "Coins: ";
    for (int m = M; m > 0; )
    {
        for (int i = 0; i < d; i++)
        {
            if (mnc[m - coins[i]] + 1 == mnc[m])
            {
                cout << coins[i] << " ";
                m -= coins[i];
                break;
            }
        }
    }

    return mnc[M];
}

int main()
{
    int M, d, x;
    cin >> M >> d;
    vector<int> coins;
    for (int i = 1; i <= d; i++)
    {
        cin >> x;
        coins.push_back(x);
    }
    int totalcoins = CoinChange(M, coins, d);
    return 0;
}
