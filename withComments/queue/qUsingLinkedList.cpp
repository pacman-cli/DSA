#include <iostream>
using namespace std;

// Define a Node class to represent each element in the queue
class Node {
public:
  int data;   // The data part of the node (stores the value)
  Node *next; // Pointer to the next node in the queue

  // Constructor to initialize a node with a given value, and set next to NULL
  Node(int val) {
    data = val;
    next = NULL;
  }
};

// Define a Queue class to represent the queue itself
class Queue {
private:
  Node *front; // Pointer to the front node of the queue
  Node *rear;  // Pointer to the rear node of the queue

public:
  // Constructor to initialize the queue with both front and rear as NULL (empty
  // queue)
  Queue() { front = rear = NULL; }

  // Function to check if the queue is empty
  bool isEmpty() {
    return front == NULL; // If front is NULL, the queue is empty
  }

  // Enqueue function to add an element to the rear of the queue
  void enqueue(int x) {
    // Create a new node with the value 'x'
    Node *newNode = new Node(x);

    // If the queue is empty, both front and rear will point to the new node
    if (rear == NULL) {
      front = rear = newNode;
      cout << x << " enqueued to queue\n";
      return;
    }

    // Otherwise, add the new node to the end of the queue and update the rear
    // pointer
    rear->next = newNode;
    rear = newNode;

    cout << x << " enqueued to queue\n";
  }

  // Dequeue function to remove and return the front element from the queue
  int dequeue() {
    // If the queue is empty, show an error and return a special value
    if (isEmpty()) {
      cout << "Queue is empty\n";
      return -1;
    }

    // Store the front node's data and move the front pointer to the next node
    int dequeuedValue = front->data;
    Node *temp = front;
    front = front->next;

    // If the front becomes NULL, then set rear to NULL (queue becomes empty)
    if (front == NULL) {
      rear = NULL;
    }

    // Delete the old front node and return its data
    delete temp;
    return dequeuedValue;
  }

  // Function to get the front element of the queue without removing it
  int peek() {
    if (isEmpty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return front->data;
  }

  // Function to display the entire queue (for visualization)
  void display() {
    if (isEmpty()) {
      cout << "Queue is empty\n";
      return;
    }
    Node *temp = front; // Temporary pointer to traverse the queue
    while (temp != NULL) {
      cout << temp->data << " "; // Print the current node's data
      temp = temp->next;         // Move to the next node
    }
    cout << endl;
  }
};

// Main function to test the queue implementation
int main() {
  Queue q; // Create an instance of the Queue class

  // Perform some enqueue operations
  q.enqueue(10); // Enqueue 10 to the queue
  q.enqueue(20); // Enqueue 20 to the queue
  q.enqueue(30); // Enqueue 30 to the queue
  q.enqueue(40); // Enqueue 40 to the queue

  // Display the current state of the queue
  cout << "Queue elements: ";
  q.display();

  // Perform a dequeue operation and print the dequeued element
  cout << q.dequeue() << " dequeued from queue\n";

  // Check the element at the front of the queue
  cout << "Front element: " << q.peek() << endl;

  // Display the queue after dequeue
  cout << "Queue elements after dequeue: ";
  q.display();

  return 0; // Exit the program
}
