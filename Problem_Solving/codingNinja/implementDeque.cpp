#include <bits/stdc++.h>
class Deque
{
  int *arr;
  int front;
  int rear;
  int size;

public:
  // Initialize your data structure.
  Deque(int n)
  {
    size = n;
    arr = new int[n];
    front = rear = -1;
  }

  // Pushes 'X' in the front of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool pushFront(int x)
  {
    // check full or not
    if (front == 0 && rear == size - 1 || (rear == (front - 1) % (size - 1)))
    {
      return false;
    }
    else if (front == -1)
    {
      front = rear = 0;
    }
    else if (front == 0 && rear != size - 1)
    { // for cyclic nature
      front = n - 1;
    }
    else
    {
      front--;
    }
    arr[front] = x;
    return true;
  }

  // Pushes 'X' in the back of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool pushRear(int x)
  {
    if (front == 0 && rear == size - 1 || (rear == (front - 1) % (size - 1)))
    {
      return false;
    }
    else if (front == -1)
    {
      front = rear = 0;
    }
    else if (rear == size - 1 && front != 0)
    { // for cyclic nature
      rear = 0;
    }
    else
    {
      rear++;
    }
    arr[rear] = x;
    return true;
  }

  // Pops an element from the front of the deque. Returns -1 if the deque is
  // empty, otherwise returns the popped element.
  int popFront()
  {
    if (front == -1)
    {
      // cout << "Queue is Empty";
      return -1;
    }

    int ans = arr[rear];
    arr[rear] = -1;

    if (front == rear)
    {
      front = rear = -1; // single element
    }
    else if (rear == 0)
    {
      rear = size - 1; // to maintain the cyclic nature
    }
    else
    {
      rear--;
    }

    return ans;
  }

  // Pops an element from the back of the deque. Returns -1 if the deque is
  // empty, otherwise returns the popped element.
  int popRear()
  {
    // Write your code here.
  }

  // Returns the first element of the deque. If the deque is empty, it returns
  // -1.
  int getFront()
  {
    // Write your code here.
  }

  // Returns the last element of the deque. If the deque is empty, it returns
  // -1.
  int getRear()
  {
    // Write your code here.
  }

  // Returns true if the deque is empty. Otherwise returns false.
  bool isEmpty()
  {
    // Write your code here.
  }

  // Returns true if the deque is full. Otherwise returns false.
  bool isFull()
  {
    // Write your code here.
  }
};
