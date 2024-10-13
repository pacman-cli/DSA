#include <climits>
#include <iostream>
#include <stack>
using namespace std;

class Queue {
  stack<int> s;

public:
  Queue() {}
  void enqueue(int x) { s.push(x); }
  bool isEmpty() { return s.empty(); }
  int dequeue() {
    if (isEmpty()) {
      cout << "queue is empty" << endl;
      return INT_MAX;
    }
    stack<int> temp;
    // step 1: s->temp
    while (!s.empty()) {
      int x = s.top();
      temp.push(x);
      s.pop();
    }
    // step 2: target = temp.top()
    int y = temp.top();
    temp.pop();

    // step 3: temp->s
    while (!temp.empty()) {
      int z = temp.top();
      s.push(z);
      temp.pop();
    }
    return y;
  }
};

int main() {
  Queue q;
  q.enqueue(12);
}
