#include <iostream>
#include <stdio.h>
using namespace std;

class Queue {
  int *arr;
  int qfront;
  int rear;
  int capacity;

public:
  Queue() {
    capacity = 4;
    arr = new int[capacity];
    qfront = 0;
    rear = 0;
  }
  Queue(int n) {
    this->capacity = n;
    arr = new int[capacity];
    qfront = 0;
    rear = 0;
  }

  bool isEmpty() { return (qfront == rear); }

  void enqueue(int data) {
    if (rear == capacity) {
      capacity += 2;
      int *newArr = new int[capacity];
      for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
      }
      arr = newArr;
    }
    arr[rear] = data;
    rear++;
  }

  int dequeue() {
    if (rear == qfront) {
      return -1;
    } else {
      int ans = arr[qfront];
      arr[qfront] = -1;
      qfront++;
      if (qfront == rear) {
        qfront = 0;
        rear = 0;
      }
      return ans;
    }
  }

  int front() {
    if (isEmpty()) {
      return -1;
    } else {
      return arr[qfront];
    }
  }
};

int main() {
  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  cout << q.dequeue() << endl; // Output: 10
  cout << q.dequeue() << endl; // Output: 20

  cout << "front:" << q.front() << endl; // Output: 30

  q.enqueue(60);
  q.enqueue(70);

  cout << q.dequeue() << endl; // Output: 30
  cout << q.dequeue() << endl; // Output: 40
  cout << q.dequeue() << endl; // Output: 50

  cout << "front:" << q.front() << endl; // Output: 60

  return 0;
}
