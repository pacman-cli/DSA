#include <iostream>
#include<vector>
using namespace std;
#define INF -99999
int rodCutting(int N, vector<int>& prices, int d) {
    int maxPrice[N + 1];
    maxPrice[0] = 0;
    for (int i = 1; i <= N; i++) {
        maxPrice[i] = INF;
        for (int j = 1; j <= min(d, i); j++) {
                maxPrice[i] =min(maxPrice[i], prices[j] + maxPrice[i - j]);
            cout<<"Rod Length:"<<i<<"Maximum Profit:"<<maxPrice[i]<<endl;
        }
    }
    // Backtrack
    cout<<"Rod pices Used:";
    for (int i = N; i > 0; ) {
        for (int j = 1; j <= min(d,i); j++) {
            if (maxPrice[i] == prices[j] + maxPrice[i - j]) {
                cout << j << " ";
                i-=j;
                break;
            }
        }
    }
    cout<<endl;
    return maxPrice[N];
}
int main() {
    int N = 8;
    int d = 10;
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << "Maximum obtainable price:" << rodCutting(N, prices, d);
    return 0;
}
