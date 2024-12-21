#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    vector<int> list2 = {1, 10, 200};
    vector<int> list4;
    int x;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        list4.push_back(x);
    }
    cout << "List 4 size: " << list4.size() << endl;
    for (int i = 0; i < list4.size(); i++)
    {
        cout << i << " " << list4[i] << " ";
    }
    int i = 2;
    list4.erase(list4.begin() + i);
    for (int x : list4)
    {
        cout << x << " ";
    }
    return 0;
}