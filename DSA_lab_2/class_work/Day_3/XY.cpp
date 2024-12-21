#include <bits/stdc++.h>
using namespace std;
long long power(int x, int y) {
    // if(y==1) return x;
    if (y == 0) return 1;

    long long p = power(x, y / 2);
    if (y % 2 == 0)
        return p * p;
    else
        return x * p * p;
}
int main() {
    cout << power(3, 4);
}
