#include <iostream>
using namespace std;

int fibonacci(int n) {
  // base case
  if (n == 0 || n == 1) {
    return n;
  }
  // recursive case
  int ans = fibonacci(n - 1) + fibonacci(n - 2);
  return ans;
}

int power(int a) {
  // base case
  if (a == 0) {
    return 1;
  }
  return 2 * power(a - 1);
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

void print(int n) {
  // base case
  if (n == 0)
    return;
  // recursive case
  cout << n << " ";
  return print(n - 1);
}

void printHead(int n) {
  // base case
  if (n == 0)
    return;

  // recursive case
  printHead(n - 1);

  cout << n << " ";
}
void reachHome(int src, int dest) {
  cout << "src:" << src << " dest:" << dest << endl;
  // base case
  if (src == dest) {
    cout << "Reached Home" << endl;
    return;
  }
  // processing
  src++;
  // recursive case
  reachHome(src, dest);
}
int main() {
  int n;
  cin >> n;
  cout << "Fibonacci: " << fibonacci(n) << endl;
  print(n);
  printHead(n);
  cout << endl;
  int ans = power(n);
  cout << "Power: " << ans << endl;
  cout << "Factorial: " << factorial(n) << endl;
  int src = 1, dest = 10;
  reachHome(src, dest);
  return 0;
}
