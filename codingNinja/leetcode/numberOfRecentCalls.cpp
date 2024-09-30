#include <bits/stdc++.h>
#include <queue>
using namespace std;
class RecentCounter {
public:
  queue<int> q;
  RecentCounter() {}
  int ping(int t) {
    q.push(t);
    while (!q.empty() && q.front() < t - 3000) {
      q.pop();
    }
    return q.size();
  }
};

int main() {
  RecentCounter rec;

  int a = rec.ping(1);
  int b = rec.ping(100);
  int c = rec.ping(3001);
  int d = rec.ping(3002);

  cout << a << endl; // Output: 1
  cout << b << endl; // Output: 2
  cout << c << endl; // Output: 3
  cout << d << endl; // Output: 3
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
