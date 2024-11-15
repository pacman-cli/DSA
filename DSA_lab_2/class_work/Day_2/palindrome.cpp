#include<iostream>
using namespace std;

int reverse(int n, int rev) {
    if (n == 0)
        return rev;  

    int digit = n % 10;
    rev = rev * 10 + digit;
   

    return reverse(n/10, rev);
}

int main() {
    int n;
    cin >> n;
    
    int rev = reverse(n, 0); 
    
    if (rev == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    return 0;
}
