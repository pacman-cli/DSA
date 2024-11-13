#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[100];
    cin >> str;
    cout << str << endl;
    cin.sync();        // clear the input buffer
    cin.get(str, 100); // get the input
    cout << str << endl;
    return 0;
}