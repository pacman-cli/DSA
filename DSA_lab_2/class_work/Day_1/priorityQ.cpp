// This program demonstrates the use of priority queue with custom comparator
#include <bits/stdc++.h>
using namespace std;

// Structure to hold a pair of integers
struct Pair {
    int a, b;
};

// Custom comparator for sorting by 'a' value in descending order
struct comp_a {
    bool operator()(Pair const &p1, Pair const &p2) {
        return p1.a < p2.a;  // For max heap (largest a value has highest priority)
    }
};

int main() {
    // Create priority queue with custom comparator
    priority_queue<Pair, vector<Pair>, comp_a> Q;

    // Test data
    Pair arr[] = {
        {0, 5},   // a=0, b=5
        {5, 5},   // a=5, b=5
        {20, 6},  // a=20, b=6
        {3, 6},   // a=3, b=6
        {23, 5}   // a=23, b=5
    };

    // Push all pairs into priority queue
    for (int i = 0; i < 5; ++i) {
        Q.push(arr[i]);
    }

    // Pop and print elements (will come out in order of decreasing 'a' values)
    cout << "Pairs in priority order (by 'a' value):" << endl;
    while (!Q.empty()) {
        Pair p = Q.top();
        Q.pop();
        cout << "a:" << p.a << " b:" << p.b << endl;
    }
    return 0;
}

/* Additional priority queue examples:

// Example 1: Min heap comparator (smallest 'a' value has highest priority)
struct comp_min {
    bool operator()(Pair const &p1, Pair const &p2) {
        return p1.a > p2.a;
    }
};

// Example 2: Compare by 'b' value
struct comp_b {
    bool operator()(Pair const &p1, Pair const &p2) {
        return p1.b < p2.b;
    }
};

// Example 3: Compare by sum of a and b
struct comp_sum {
    bool operator()(Pair const &p1, Pair const &p2) {
        return (p1.a + p1.b) < (p2.a + p2.b);
    }
};

// Example 4: Compare by ratio of b/a
struct comp_ratio {
    bool operator()(Pair const &p1, Pair const &p2) {
        return (double)p1.b/p1.a < (double)p2.b/p2.a;
    }
};

// Example 5: Multi-level comparison
struct comp_multi {
    bool operator()(Pair const &p1, Pair const &p2) {
        if (p1.a != p2.a) return p1.a < p2.a;
        return p1.b < p2.b;
    }
};

Usage examples:
priority_queue<Pair, vector<Pair>, comp_min> minQ;    // Min heap
priority_queue<Pair, vector<Pair>, comp_b> bQ;        // Sort by b
priority_queue<Pair, vector<Pair>, comp_sum> sumQ;    // Sort by sum
priority_queue<Pair, vector<Pair>, comp_ratio> ratioQ;// Sort by ratio
priority_queue<Pair, vector<Pair>, comp_multi> multiQ;// Multi-level sort

Example operations:
void priorityQueueOperations() {
    priority_queue<Pair, vector<Pair>, comp_min> Q;

    // Push elements
    Q.push({1, 2});
    Q.push({3, 4});

    // Access top element
    Pair top = Q.top();

    // Check size and emptiness
    int size = Q.size();
    bool isEmpty = Q.empty();

    // Pop all elements
    while (!Q.empty()) {
        cout << Q.top().a << "," << Q.top().b << endl;
        Q.pop();
    }
}
*/
