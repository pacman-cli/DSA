#include <iostream>
#include <climits>
#include <stack> // Including the stack library to use the STL stack class
using namespace std;

class Queue {
  stack<int> s; // Using a stack to store elements of the queue
public:
  Queue() {
    // Default constructor
  }

  // Method to add an element to the queue (enqueue)
  void enqueue(int x) {
    s.push(x); // Add the element to the stack
  }

  // Method to check if the queue is empty
  bool isEmpty() {
    return s.empty(); // Check if the stack is empty
  }

  // Method to remove an element from the queue (dequeue)
  int dequeue() {
    // If the queue (stack) is empty, return an error value
    if (isEmpty()) {
      cout << "queue is empty" << endl;
      return INT_MAX; // Return a large value to indicate empty condition
    }

    stack<int> temp; // Temporary stack to reverse the order

    // Step 1: Move elements from 's' to 'temp' (reverse the order)
    while (!s.empty()) {
      int x = s.top(); // Get the top element of the stack 's'
      temp.push(x);    // Push it onto the temporary stack 'temp'
      s.pop();         // Remove the element from 's'
    }

    // Step 2: The top of 'temp' is the element that should be dequeued
    int y =
        temp.top(); // Store the front of the queue (which is the top of 'temp')
    temp.pop();     // Remove the dequeued element

    // Step 3: Move the remaining elements back to 's' from 'temp'
    while (!temp.empty()) {
      int z = temp.top(); // Get the top element of 'temp'
      s.push(z);          // Push it back to 's'
      temp.pop();         // Remove it from 'temp'
    }

    return y; // Return the dequeued element
  }
};

int main() {
  Queue q;       // Create a Queue object
  q.enqueue(12); // Enqueue an element

  // Dequeue elements and print them
  cout << q.dequeue() << endl; // This will dequeue 12 and print it

  return 0;
}
