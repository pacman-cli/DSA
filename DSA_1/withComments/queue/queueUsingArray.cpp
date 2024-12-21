#include <iostream>
using namespace std;

class Queue {
  int front, rear,
      size;     // Front and rear pointers, and the current size of the queue
  int *arr;     // Pointer to the array holding the queue elements
  int capacity; // Maximum capacity of the queue

public:
  // Default constructor initializes a queue with a capacity of 4
  Queue(int cap = 4) {
    capacity = cap;          // Set the capacity
    arr = new int[capacity]; // Allocate memory for the array
    front = rear = size = 0; // Initialize front, rear, and size
  }

  // Destructor to clean up allocated memory
  ~Queue() {
    delete[] arr; // Free the memory allocated for the array
  }

  // Check if the queue is full
  bool isFull() {
    return size == capacity; // If size equals capacity, the queue is full
  }

  // Check if the queue is empty
  bool isEmpty() {
    return size == 0; // If size is zero, the queue is empty
  }

  // Add an element to the rear of the queue
  void enqueue(int value) {
    if (isFull()) {
      cout << "Queue is full!" << endl; // Print a message if the queue is full
      return;
    }
    arr[rear] = value;            // Add the value to the rear
    rear = (rear + 1) % capacity; // Circular increment of rear
    size++;                       // Increment the size
  }

  // Remove and return the element from the front of the queue
  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty!"
           << endl; // Print a message if the queue is empty
      return -1;    // Return -1 to indicate an empty queue
    }
    int value = arr[front];         // Get the value from the front
    front = (front + 1) % capacity; // Circular increment of front
    size--;                         // Decrement the size
    return value;                   // Return the dequeued value
  }

  // Display all elements in the queue
  void display() {
    if (isEmpty()) {
      cout << "Queue is empty!"
           << endl; // Print a message if the queue is empty
      return;
    }
    int i = front; // Start from the front
    int count = 0; // Counter for the number of elements displayed
    while (count < size) {
      cout << arr[i] << " ";  // Print the current element
      i = (i + 1) % capacity; // Circular increment of index
      count++;                // Increment the counter
    }
    cout << endl; // Print a newline character after displaying all elements
  }
};

int main() {
  Queue q(5); // Create a queue with capacity 5

  q.enqueue(10); // Add elements to the queue
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  cout << "Queue contents: ";
  q.display(); // Display the queue contents

  cout << "Dequeued: " << q.dequeue() << endl; // Dequeue and print an element

  cout << "Queue contents after dequeue: ";
  q.display(); // Display the queue contents after dequeue

  return 0; // End of the program
}
