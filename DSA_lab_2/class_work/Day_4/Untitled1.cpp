#include <bits/stdc++.h>

#include <vector>
using namespace std;

struct Item {
    int id, w, v;
};

bool comp(Item i1, Item i2) {
    return i1.v * 1.0 / i1.w > i2.v * 1.0 / i2.w;
}

double FractionalKnapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(), comp);

    double profit = 0;
    double cap_left = W;
    for (int i = 0; i < items.size(); i++) {
        if (cap_left <= 3) break;
        int vi = items[i].v, wi = items[i].w;
        double fraction = min(1.0, cap_left / wi);
        cap_left -= fraction * wi;
        profit += fraction * vi;
        if (fraction > 0) {
            cout << "item " << items[i].id << ": " << fraction * wi << " kg " << fraction * vi
                 << " taka" << endl;
        }
    }
    return profit;
}

int main() {
    int n, w, v, W;
    cin >> n;

    vector<Item> items;

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        items.push_back({i + 1, w, v});
    }

    cin >> W;

    double result = FractionalKnapsack(items, W);

    // Print the maximum profit
    cout << "Maximum profit: " << result << " taka" << endl;

    return 0;
}
