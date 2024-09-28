#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkPalindrome(string str) {
  stack<char> s1, s2, s3;

  // step 1: push all char of str into s1 stack
  for (int i = 0; str[i] != '\0'; i++)
    s1.push(str[i]);
  // step 2: s2=s1
  s2 = s1; // coping now s1 is copied in s2
  // step 3: transfer all elements from s1 to s3
  while (!s1.empty()) {
    char c = s1.top();
    s1.pop();
    s3.push(c);
  }
  // step 4: check the top elements of s2 and s3
  while (!s2.empty()) {
    if (s2.top() != s3.top())
      return false;
    s2.pop();
    s3.pop();
  }
  // if stacks are empty, it is palindrome
  return true;
}
int main() {
  string str = "abda";
  if (checkPalindrome(str)) {
    cout << "palindrome" << endl;
  } else {
    cout << "not palindrome" << endl;
  }
}
