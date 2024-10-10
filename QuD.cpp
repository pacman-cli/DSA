#include <bits/stdc++.h>
using namespace std;

class Queue
{
  int *arr;     // Array to store queue elements
  int qfront;   // Index for the front of the queue
  int rear;     // Index for the rear of the queue
  int size;     // Current capacity of the queue
  int capacity; // Maximum capacity before resizing

public:
  // Constructor to initialize the queue with a default capacity
  Queue()
  {
    capacity = 4;            // Initial capacity of the queue
    arr = new int[capacity]; // Dynamically allocate array with initial capacity
    qfront = 0;              // Front index initialized to 0
    rear = 0;                // Rear index initialized to 0
  }
  Queue(int n)
  {
    this->capacity = n;
    arr = new int[capacity];
    qfront = 0;
    rear = 0;
  }
  /*----------------- Public Functions of Queue -----------------*/

  // Function to check if the queue is empty
  bool isEmpty()
  {
    return (qfront == rear); // True if front equals rear (queue is empty)
  }

  // Function to enqueue (insert) a new element
  void enqueue(int data)
  {
    // Check if the queue is full
    if (rear == capacity)
    {
      // Resize the queue if it's full
      capacity += 2;
      int *newArr =
          new int[capacity]; // Create a new array with double capacity
      for (int i = 0; i < capacity; i++)
      {
        newArr[i] = arr[i]; // Copy old elements to the new array
      }
      // capacity *= 2; // Update the capacity
      // delete[] arr;  // Delete the old array
      arr = newArr; // Point arr to the new array
    }

    // Insert the new element at the rear of the queue
    arr[rear] = data;
    rear++; // Increment rear to point to the next available position
  }

  // Function to dequeue (remove) the front element
  int dequeue()
  {
    // Check if the queue is empty
    if (rear == qfront)
    {
      return -1; // Return -1 if queue is empty
    }
    else
    {
      int ans = arr[qfront]; // Get the front element
      arr[qfront] = -1;      // Mark the front element as removed
      qfront++;              // Increment the front index

      // Reset front and rear to 0 if the queue becomes empty after dequeue
      if (qfront == rear)
      {
        qfront = 0;
        rear = 0;
      }
      return ans; // Return the dequeued element
    }
  }

  // Function to return the front element of the queue without removing it
  int front()
  {
    if (isEmpty())
    {
      return -1; // Return -1 if queue is empty
    }
    else
    {
      return arr[qfront]; // Return the front element
    }
  }

  // Destructor to free the dynamically allocated memory
  // ~Queue()
  // {
  //     delete[] arr; // Free the dynamically allocated array
  // }
};

int main()
{
  Queue q;

  // Enqueue some elements
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);

  // Enqueue another element to trigger dynamic resizing
  q.enqueue(50);

  // Dequeue and display elements
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 10
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 20

  // Check front element
  cout << "Front: " << q.front() << endl; // Output: 30

  // Enqueue more elements
  q.enqueue(60);
  q.enqueue(70);

  // Dequeue more elements
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 30
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 40
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 50
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 60
  cout << "Dequeue: " << q.dequeue() << endl; // Output: 70

  return 0;
}
