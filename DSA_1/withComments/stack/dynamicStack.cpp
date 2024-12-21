#include <iostream>
#include <climits>
using namespace std;

class Stack {
  int n, top; // 'n' is the current size of the stack, 'top' is the index of the
              // top element
  int *s; // 's' is a pointer to dynamically allocated array representing the
          // stack
public:
  // Default constructor initializes a stack of size 4
  Stack() {
    n = 4;          // Set initial stack size to 4
    top = -1;       // Initialize top as -1, indicating an empty stack
    s = new int[n]; // Dynamically allocate an array of size 'n'
  }

  // Parameterized constructor allows user to create a stack of a specific size
  Stack(int n) {
    this->n = n;    // Set the stack size to the value provided by the user
    top = -1;       // Initialize top as -1, indicating an empty stack
    s = new int[n]; // Dynamically allocate an array of size 'n'
  }

  // Function to check if the stack is empty
  int isEmpty() {
    if (top == -1)   // If top is -1, the stack is empty
      return 1;    // Return 1 (true) if the stack is empty
    else
      return 0; // Return 0 (false) if the stack is not empty
  }

  // Function to check if the stack is full
  int isFull() {
    if (top == n - 1) // If top equals n-1, the stack is full
      return 1;       // Return 1 (true) if the stack is full
    else
      return 0; // Return 0 (false) if the stack is not full
  }

  // Function to push an element onto the stack
  void push(int x) {
    if (isFull()) {           // Check if the stack is full
      n += 2;                 // Increase the stack size by 2
      int *temp = new int[n]; // Create a new array with increased size

      // Copy all elements from the old stack to the new one
      for (int i = 0; i <= top; i++) {
        temp[i] = s[i];
      }

      s = temp; // Update 's' to point to the new array
    }
    top++;      // Increment top to the next index
    s[top] = x; // Place the new value 'x' at the top of the stack
  }

  // Function to pop an element from the stack
  int pop() {
    if (isEmpty()) { // Check if the stack is empty
      // If empty, print an error message and return a special value (INT_MAX)
      cout << "stack is empty" << endl;
      return INT_MAX;
    } else {
      int y = s[top]; // Store the top value in 'y'
      top--;          // Decrease top to remove the element
      return y;       // Return the popped value
    }
  }
};

int main() {
  Stack s1;    // Create a stack s1 of size 4 (default constructor)
  Stack s2(3); // Create another stack s2 of size 3 (parameterized constructor)

  // Push elements onto stack s1
  s1.push(3);  // Push 3 onto the stack
  s1.push(31); // Push 31 onto the stack
  s1.push(13); // Push 13 onto the stack
  s1.push(32); // Push 32 onto the stack (stack is now full)
  s1.push(35); // Stack dynamically resizes and then 35 is added

  // Pop elements from stack s1 and print them
  while (!s1.isEmpty()) {     // While the stack is not empty
    cout << s1.pop() << endl; // Pop and print each element
  }
}
