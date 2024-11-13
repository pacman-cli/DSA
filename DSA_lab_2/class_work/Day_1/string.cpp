#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1 = "Hello World";
    cout << str1 << endl;

    char chr_str[] = "Hello Universe";
    string str2 = string(chr_str);
    cout << str2 << endl;

    cout << str1.length() << endl;

    cout << "str1[0]: " << str1[0] << " str1[6]: " << str1[6] << endl;
    str1 += ".";
    cout << str1 << endl;
    str2 += ".";
    str2 += str1;
    cout << str2 << endl;

    string word, line;
    cin >> word;
    cin.sync();
    cout << word << endl;
    getline(cin, line);
    cout << line << endl;
    return 0;
}