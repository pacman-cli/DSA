#include <iostream>
#include <climits>
using namespace std;

class Queue {
  int rear, frnt, Size; // 'rear' and 'frnt' represent the rear and front
                        // indices, 'Size' is the queue's capacity.
  int *q; // 'q' is a pointer to dynamically allocated array representing the
          // queue.
public:
  // Default constructor initializes a queue with a default size of 4
  Queue() {
    Size = 4;          // Set the queue size to 4
    rear = frnt = -1;  // Both rear and front are initialized to -1, meaning the
                       // queue is empty
    q = new int[Size]; // Dynamically allocate an array of size 'Size'
  }

  // Parameterized constructor allows creating a queue with a specific size
  Queue(int n) {
    Size = n;         // Set the queue size to the user-provided value 'n'
    rear = frnt = -1; // Initialize rear and front to -1 (empty queue)
    q = new int[n];   // Dynamically allocate an array of size 'n'
  }

  // Function to check if the queue is full
  int isFull() {
    // The queue is full if moving 'rear' one step ahead would equal 'frnt'
    if ((rear + 1) % Size == frnt)
      return 1; // Return 1 (true) if the queue is full
    else
      return 0; // Return 0 (false) otherwise
  }

  // Function to check if the queue is empty
  int isEmpty() {
    // The queue is empty if both 'rear' and 'frnt' are set to -1
    if (rear == -1 && frnt == -1)
      return 1; // Return 1 (true) if the queue is empty
    else
      return 0; // Return 0 (false) otherwise
  }

  // Function to add an element 'x' to the queue (enqueue)
  void enqueue(int x) {
    if (isFull()) {
      // If the queue is full, print an error message
      cout << "queue is full" << endl;
    } else if (isEmpty()) {
      // If the queue is empty, set 'frnt' and 'rear' to 0 and add the element
      frnt = rear = 0;
      q[rear] = x;
    } else {
      // Move 'rear' to the next position in a circular fashion
      rear = (rear + 1) % Size;
      q[rear] = x; // Add the element to the new rear position
    }
  }

  // Function to remove and return an element from the queue (dequeue)
  int dequeue() {
    if (isEmpty()) {
      // If the queue is empty, print an error message and return a special
      // value (INT_MAX)
      cout << "queue is empty" << endl;
      return INT_MAX;
    } else if (frnt == rear) {
      // If there is only one element, remove it and reset the queue to empty
      int y = q[frnt];
      frnt = rear = -1; // Reset to empty condition
      return y;         // Return the dequeued element
    } else {
      // Dequeue an element and move 'frnt' to the next position in a circular
      // manner
      int y = q[frnt];
      frnt = (frnt + 1) % Size;
      return y; // Return the dequeued element
    }
  }
};

int main() {
  Queue q(5); // Create a queue of size 5

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  cout << "Dequeue: " << q.dequeue() << endl; // Removes 10
  cout << "Dequeue: " << q.dequeue() << endl; // Removes 20

  q.enqueue(60);
  q.enqueue(70);

  while (!q.isEmpty()) {
    cout << "Dequeue: " << q.dequeue() << endl; // Dequeues remaining elements
  }
}
