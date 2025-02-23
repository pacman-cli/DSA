#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Stack {
  queue<int> q;

public:
  bool isEmpty() { return q.empty(); }
  void Push(int x) {
    q.push(x);
    int size = q.size();
    for (int i = 0; i < size - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }
  int Pop() {
    if (isEmpty()) {
      cout << "Queue is empty";
      return INT_MAX;
    }
    int ans = q.front();
    q.pop();
    return ans;
  }
  int Top() { return q.front(); }
  int Size() { return q.size(); }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Pop(); // removes 2
  s.Push(4);
  s.Push(1);
  // cout << "top: " << s.Top() << endl;
  // cout << "Size: " << s.Size() << endl;
  // cout << "deleted element: " << s.Pop() << endl;
  // cout << "Top after removing: " << s.Top() << endl;
  while (!s.isEmpty()) {
    cout << s.Pop() << endl;
  }
}
