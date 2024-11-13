#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1 = true;
    bool b2 = false;
    bool b3 = 0;
    bool b4 = 1;
    if (b1)
    {
        cout << "Inside first if" << endl;
        if (b2)
        {
            cout << "Inside first nested if" << endl;
        }
        if (b3)
        {
            cout << "Inside second nested if" << endl;
        }
        if (b4)
        {
            cout << "Inside third nested if" << endl;
        }
    }
    return 0;
}