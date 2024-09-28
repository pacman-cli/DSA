#include <iostream>
using namespace std;

// Node class for linked list
class QueueNode {
public:
  int data;        // Data stored in the node
  QueueNode *next; // Pointer to the next node

  // Constructor to initialize a node with a given value
  QueueNode(int value) : data(value), next(nullptr) {}
};

class Queue {
  QueueNode *front; // Pointer to the front of the queue
  QueueNode *rear;  // Pointer to the rear of the queue

public:
  // Constructor initializes an empty queue
  Queue() : front(nullptr), rear(nullptr) {}

  // Destructor to free allocated nodes
  ~Queue() {
    while (!isEmpty()) {
      dequeue(); // Dequeue all elements to free memory
    }
  }

  // Check if the queue is empty
  bool isEmpty() {
    return front == nullptr; // If front is nullptr, the queue is empty
  }

  // Add an element to the rear of the queue
  void enqueue(int value) {
    QueueNode *newNode = new QueueNode(value); // Create a new node
    if (isEmpty()) {
      front = rear =
          newNode; // Queue was empty, new node is both front and rear
    } else {
      rear->next = newNode; // Add the new node to the end of the queue
      rear = newNode;       // Update the rear pointer
    }
  }

  // Remove and return the element from the front of the queue
  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty!"
           << endl; // Print a message if the queue is empty
      return -1;    // Return -1 to indicate an empty queue
    }
    QueueNode *temp = front; // Save the front node
    int value = front->data; // Get the value from the front node
    front = front->next;     // Move the front pointer to the next node
    if (front == nullptr) {
      rear = nullptr; // Queue is now empty, update rear pointer
    }
    delete temp;  // Free the memory of the old front node
    return value; // Return the dequeued value
  }

  // Display all elements in the queue
  void display() {
    if (isEmpty()) {
      cout << "Queue is empty!"
           << endl; // Print a message if the queue is empty
      return;
    }
    QueueNode *temp = front; // Start from the front
    while (temp) {
      cout << temp->data << " "; // Print the current node's data
      temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a newline character after displaying all elements
  }
};

int main() {
  Queue q; // Create an empty queue

  q.enqueue(10); // Add elements to the queue
  q.enqueue(20);
  q.enqueue(30);

  cout << "Queue contents: ";
  q.display(); // Display the queue contents

  cout << "Dequeued: " << q.dequeue() << endl; // Dequeue and print an element

  cout << "Queue contents after dequeue: ";
  q.display(); // Display the queue contents after dequeue

  return 0; // End of the program
}
