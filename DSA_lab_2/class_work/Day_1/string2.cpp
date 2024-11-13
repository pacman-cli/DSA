#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1 = "Hello";
    string str2 = str1;
    str1[0] = 'y';
    cout << str1 << " " << str2 << endl;
    if (str2 == str1)
    {
        cout << "str1 and str2 both changed!" << endl;
    }
    if (str2 == "hello")
    {
        cout << "str2 did not changed" << endl;
    }
    return 0;
}