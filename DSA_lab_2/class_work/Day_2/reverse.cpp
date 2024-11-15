#include <iostream>
using namespace std;
void reverse(int n) {
  if (n == 0)
    return;

  int digit = n % 10;
  cout << digit;
  n = n / 10;

  reverse(n);
}

int main() {
  int n;
  cin >> n;
  reverse(n);
}
