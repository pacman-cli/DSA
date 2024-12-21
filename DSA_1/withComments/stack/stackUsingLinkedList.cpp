#include <iostream>
using namespace std;

// Define a Node class to represent each element in the stack
class Node {
public:
  int data;   // The data part of the node
  Node *next; // Pointer to the next node in the stack

  // Constructor to initialize a node with a given value and next pointer as
  // NULL
  Node(int val) {
    data = val;
    next = NULL;
  }
};

// Define a Stack class to represent the stack itself
class Stack {
private:
  Node *top; // Pointer to the top node in the stack

public:
  // Constructor to initialize the stack with the top set to NULL (empty stack)
  Stack() { top = NULL; }

  // Push function to add an element to the top of the stack
  void push(int x) {
    Node *newNode = new Node(x); // Create a new node with the value 'x'

    if (top == NULL) {
      // If stack is empty, the new node becomes the top node
      top = newNode;
    } else {
      // Otherwise, insert the new node at the top and update the top pointer
      newNode->next = top;
      top = newNode;
    }

    cout << x << " pushed to stack\n";
  }

  // Pop function to remove the top element from the stack
  int pop() {
    if (top == NULL) {
      // If the stack is empty, show an error and return a special value
      cout << "Stack underflow\n";
      return -1;
    } else {
      // Store the top node's data and update the top pointer to the next node
      int popped = top->data;
      Node *temp = top;
      top = top->next;
      delete temp; // Free the memory of the old top node
      return popped;
    }
  }

  // Peek function to return the top element without removing it
  int peek() {
    if (top == NULL) {
      // If the stack is empty, return a special value
      cout << "Stack is empty\n";
      return -1;
    } else {
      // Return the data at the top of the stack
      return top->data;
    }
  }

  // Function to check if the stack is empty
  bool isEmpty() { return top == NULL; }

  // Function to display the entire stack (for visualization)
  void display() {
    if (isEmpty()) {
      cout << "Stack is empty\n";
      return;
    }
    Node *temp = top; // Temporary pointer to traverse the stack
    while (temp != NULL) {
      cout << temp->data << " "; // Print the current node's data
      temp = temp->next;         // Move to the next node
    }
    cout << endl;
  }
};

// Main function to test the stack implementation
int main() {
  Stack s; // Create an instance of the Stack class

  // Perform some operations on the stack
  s.push(10); // Push 10 onto the stack
  s.push(20); // Push 20 onto the stack
  s.push(30); // Push 30 onto the stack

  cout << "Top element: " << s.peek() << endl; // Peek the top element

  s.display(); // Display the entire stack

  cout << s.pop() << " popped from stack\n";   // Pop the top element
  cout << "Top element: " << s.peek() << endl; // Peek the new top element

  s.display(); // Display the stack after popping an element

  return 0; // Exit the program
}
