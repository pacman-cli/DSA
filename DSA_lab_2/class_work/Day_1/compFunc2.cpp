#include <bits/stdc++.h>
using namespace std;
struct Pair
{
    int a, b;
};
bool comp2(Pair p1, Pair p2)
{
    return p1.b / p1.b < p2.b / p2.a;
}
int main()
{
    Pair arr[] = {{5, 100}, {3, 9}, {3, 12}, {1, 6}, {5, 5}, {8, 16}};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + len, comp2);

    for (int i = 0; i < len; i++)
    {
        cout << "a:" << arr[i].a << " " << "b:" << arr[i].b << "" << "ratio:" << arr[i].b / arr[i].a << " ";
    }
    cout << endl;
    return 0;
}