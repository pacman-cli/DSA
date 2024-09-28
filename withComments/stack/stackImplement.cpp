#include <iostream>
using namespace std;

// Define a class for Stack
class Stack {
private:
  int top;
  int arr[5]; // Fixed size stack

public:
  Stack() {
    top = -1; // Initialize the top of the stack as -1 (empty stack)
    for (int i = 0; i < 5; i++) {
      arr[i] = 0; // Initialize all elements of the array to 0
    }
  }

  // Check if the stack is empty
  bool isEmpty() { return top == -1; }

  // Check if the stack is full
  bool isFull() { return top == 4; }

  // Push an element onto the stack
  void push(int value) {
    if (isFull()) {
      cout << "Stack overflow! Cannot push " << value << endl;
    } else {
      top++;
      arr[top] = value;
      cout << "Pushed " << value << " onto the stack." << endl;
    }
  }

  // Pop an element from the stack
  int pop() {
    if (isEmpty()) {
      cout << "Stack underflow! Cannot pop from the stack." << endl;
      return 0;
    } else {
      int poppedValue = arr[top];
      arr[top] = 0;
      top--;
      return poppedValue;
    }
  }

  // Get the element at the top of the stack
  int peek() {
    if (isEmpty()) {
      cout << "Stack is empty." << endl;
      return 0;
    } else {
      return arr[top];
    }
  }

  // Display the elements of the stack
  void display() {
    cout << "Stack elements: ";
    for (int i = 4; i >= 0; i--) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Stack stack;

  // Push elements onto the stack
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50);

  // Trying to push an element into a full stack
  stack.push(60);

  // Display the current stack
  stack.display();

  // Pop elements from the stack
  cout << "Popped element: " << stack.pop() << endl;
  cout << "Popped element: " << stack.pop() << endl;

  // Display the stack after popping
  stack.display();

  // Peek at the top element of the stack
  cout << "Top element is: " << stack.peek() << endl;

  return 0;
}
