#include <iostream>
using namespace std;

int Fib(int n, int F[]) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (F[n - 1] == -1) {
        F[n - 1] = Fib(n - 1, F);
    }
    if (F[n - 2] == -1) {
        F[n - 2] = Fib(n - 2, F);
    }
    return F[n - 1] + F[n - 2];
}

int main() {
    int n;
    cin >> n;
    int F[n]; 
    for (int i = 0; i < n; i++) {
        F[i] = -1; 
    }
    int fib = Fib(n, F);
    cout << fib << endl; 
    return 0;
}
