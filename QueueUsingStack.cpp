#include <climits>
#include <iostream>
#include <stack>
using namespace std;

class Queue {
  stack<int> s; // Using one stack to implement the queue

public:
  Queue() {}

  // Enqueue operation to push elements onto the stack
  void enqueue(int x) { s.push(x); }

  // Check if the queue is empty
  bool isEmpty() { return s.empty(); }

  // Dequeue operation using recursion
  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return INT_MAX;
    }

    // Get the top element
    int topElement = s.top();
    s.pop();

    // If it's the last element, return it (base case)
    if (s.empty()) {
      return topElement;
    }

    // Recursively call dequeue to get to the front of the queue
    int result = dequeue();

    // Push the element back into the stack to maintain the original order
    s.push(topElement);

    return result;
  }
};

int main() {
  Queue q;
  q.enqueue(12);
  q.enqueue(23);
  q.enqueue(34);

  cout << "Dequeue: " << q.dequeue() << endl; // Should return 12
  q.enqueue(45);
  cout << "Dequeue: " << q.dequeue() << endl; // Should return 23
  cout << "Dequeue: " << q.dequeue() << endl; // Should return 34
  cout << "Dequeue: " << q.dequeue() << endl; // Should return 45
  cout << "Dequeue: " << q.dequeue()
       << endl; // Queue is empty, should return INT_MAX

  return 0;
}
