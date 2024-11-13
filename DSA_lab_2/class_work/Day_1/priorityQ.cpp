#include <bits/stdc++.h>
using namespace std;
struct Pair
{
    int a, b;
};
struct comp_a
{
    bool operator()(
        Pair const &p1, Pair const &p2)
    {
        return p1.a < p2.a;
    }
};
int main()
{
    priority_queue<Pair, vector<Pair>, comp_a> Q;
    Pair arr[] = {
        {0, 5},
        {5, 5},
        {20, 6},
        {3, 6},
        {23, 5}};
    for (int i = 0; i < 5; ++i)
    {
        Q.push(arr[i]);
    }
    while (!Q.empty())
    {
        Pair p = Q.top();
        Q.pop();
        cout << p.a << " " << p.b << endl;
    }
    return 0;
}