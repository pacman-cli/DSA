#include <bits/stdc++.h>

#include <queue>
using namespace std;
struct comp {
    int getSum(const string &s) const {
        int sum = 0;
        for (char c : s) {
            sum += c;
        }
        return sum;
    }
    bool operator()(const string &s1, const string &s2) {
        return getSum(s1) > getSum(s2);
    }
};
int main() {
    int n;
    cin >> n;
    priority_queue<string, vector<string>, comp> Q;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        Q.push(name);
    }
    while (!Q.empty()) {
        cout << Q.top() << endl;
        Q.pop();
    }
    return 0;
}
