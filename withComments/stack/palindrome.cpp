#include <iostream>
#include <stack> // Include the stack library for using STL stack
#include <string>
using namespace std;

bool checkPalindrome(string str) {
  // Declare three stacks for character comparison
  stack<char> s1, s2, s3;

  // Step 1: Push all characters of 'str' into stack s1
  for (int i = 0; str[i] != '\0'; i++) {
    s1.push(str[i]); // Push each character onto stack s1
  }

  // Step 2: Copy all elements of s1 into stack s2
  s2 = s1; // s2 is now a copy of s1

  // Step 3: Transfer all elements from s1 into stack s3 (reversing the order)
  while (!s1.empty()) {
    char c = s1.top(); // Get the top character of s1
    s1.pop();          // Pop the character from s1
    s3.push(c);        // Push it onto s3 (this reverses the original order)
  }

  // Step 4: Compare the top elements of s2 and s3
  while (!s2.empty()) {
    // If the top elements of s2 and s3 are different, it's not a palindrome
    if (s2.top() != s3.top()) {
      return false; // If there's a mismatch, return false
    }
    s2.pop(); // Remove the top element from s2
    s3.pop(); // Remove the top element from s3
  }

  // If all characters match, the string is a palindrome
  return true;
}

int main() {
  string str = "abda"; // Input string to check

  // Call the checkPalindrome function
  if (checkPalindrome(str)) {
    cout << "palindrome" << endl; // If true, the string is a palindrome
  } else {
    cout << "not palindrome"
         << endl; // If false, the string is not a palindrome
  }
}
