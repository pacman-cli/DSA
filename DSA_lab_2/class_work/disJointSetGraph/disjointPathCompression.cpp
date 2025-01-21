#include <iostream>
using namespace std;

int E;
int V;
int p[100], rankk[100];

void make_set() {
    for (int i = 0; i < V; i++) {
        p[i] = i;
        rankk[i] = 0;
    }
}

int find_set(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find_set(p[x]);  // path compression
}

int union_sets(int s1, int s2) {
    int r1, r2;
    r1 = find_set(s1);
    r2 = find_set(s2);
    if (r1 == r2) return 0;
    if (rankk[r1] > rankk[r2]) {
        p[r2] = r1;
    } else {
        p[r1] = r2;
        if (rankk[r1] == rankk[r2]) rankk[r2]++;
    }
    return 1;
}

int main() {
    V = 10;
    E = 7;

    make_set();

    union_sets(0, 1);
    union_sets(0, 2);
    union_sets(3, 4);
    union_sets(6, 7);
    union_sets(6, 8);
    union_sets(7, 8);
    union_sets(7, 9);
    for (int i = 1; i <= V; i++) {
        cout << find_set(i) << endl;
    }

    return 0;
}
