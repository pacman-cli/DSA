#include <iostream>
using namespace std;
int V, E;
int p[100];
void set() {
    for (int i = 0; i < V; i++) {
        p[i] = i;
    }
}
int find(int x) {
    if (p[x] == x) {
        return x;
    }
    return find(p[x]);
}
int union_set(int s1, int s2) {
    int r1, r2;
    r1 = find(s1);
    r2 = find(s2);
    if (r1 == r2) {
        return 0;
    }
    p[r2] = r1;
    return 1;
}
int main() {
    V = 10;
    E = 7;
    set();

    union_set(0, 1);
    union_set(0, 2);
    union_set(3, 4);
    union_set(6, 7);
    union_set(6, 8);
    union_set(7, 8);
    union_set(7, 9);

    for (int i = 0; i < V; i++) {
        cout << find(i) << endl;
    }
}
