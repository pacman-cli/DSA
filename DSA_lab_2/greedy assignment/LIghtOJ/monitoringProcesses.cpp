#include <stdio.h>

#include <algorithm>
#define MAX 50000
using namespace std;
struct abc {
    int start, end;
} in[MAX + 5];
int heap[MAX + 5], cs, idx;
bool cmp(abc a, abc b) {
    return a.start < b.start;
}
void insert(int i) {
    int cur_node = i;
    while (cur_node > 1) {
        int prnt_node = cur_node / 2;
        if (heap[prnt_node] > heap[cur_node]) {
            swap(heap[prnt_node], heap[cur_node]);
            cur_node = prnt_node;
        } else
            break;
    }
}

void remove() {
    int k = heap[1];
    heap[1] = heap[idx];
    idx--;
    int prnt_node = 1;
    while (prnt_node * 2 <= idx) {
        int child_node = prnt_node * 2;
        if (prnt_node * 2 + 1 <= idx)
            if (heap[child_node] > heap[child_node + 1]) child_node++;
        if (heap[prnt_node] > heap[child_node]) {
            swap(heap[prnt_node], heap[child_node]);
            prnt_node = child_node;
        } else
            break;
    }
}
void solve() {
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d %d", &in[i].start, &in[i].end);
    sort(in, in + n, cmp);
    idx = 0;
    for (i = 0; i < n; i++) {
        if (idx >= 1 && heap[1] < in[i].start) {
            remove();
            idx++;
            heap[idx] = in[i].end;
            insert(idx);
        } else {
            idx++;
            heap[idx] = in[i].end;
            insert(idx);
        }
    }
    printf("Case %d: %d\n", cs, idx);
}
int main() {
    int t;
    scanf("%d", &t);
    for (cs = 1; cs <= t; cs++) {
        solve();
    }
}
