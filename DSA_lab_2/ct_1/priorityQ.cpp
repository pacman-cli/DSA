#include <bits/stdc++.h>
using namespace std;
struct Pair {
    int a, b;
};
struct comp {
    bool operator()(Pair const &p1, Pair const &p2) {
        return p1.a < p2.a;  // for max heap
    }
};
int main() {
    priority_queue<Pair, vector<Pair>, comp> Q;
    Pair arr[] = {
        {0, 5}, {5, 5}, {20, 6}, {3, 6}, {23, 5},
    };
    for (int i = 0; i < 5; i++) {
        Q.push(arr[i]);
    }
    cout << "Pair in the priority order (by 'a' value):" << '\n';
    while (!Q.empty()) {
        Pair q = Q.top();
        Q.pop();
        cout << "a:" << q.a << "b:" << q.b << endl;
    }
    return 0;
}