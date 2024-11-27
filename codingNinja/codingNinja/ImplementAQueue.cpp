#include <bits/stdc++.h>
using namespace std;
class Queue {
  int *arr;
  int front;
  int rear;
  int size;

public:
  Queue() {
    size = 1001;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  /*----------------- Public Functions of Queue -----------------*/

  bool isEmpty() {
    if (front == rear) {
      return true;
    }
    return false;
  }

  void enqueue(int data) {
    if (rear == size) {
      cout << "Queue is full";
    } else {
      arr[rear] = data;
      rear++;
    }
  }

  int dequeue() {
    if (rear == front) {
      return -1;
    } else {
      int ans = arr[front];
      arr[front] = -1;
      front++;
      if (front == rear) {
        front = 0;
        rear = 0;
      }
      return ans;
    }
  }

  int qfront() {
    if (isEmpty()) {
      cout << "Queue is empty";
      return -1;
    }
    return arr[front];
  }
};
