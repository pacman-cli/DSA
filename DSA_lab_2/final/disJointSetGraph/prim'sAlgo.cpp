#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;

// A function to find the MST using Prim's Algorithm
void prims_algorithm(vector<pair<int, pair<int, int>>> &edges) {
    vector<bool> inMST(V, false);           // To track vertices included in MST
    vector<vector<pair<int, int>>> adj(V);  // Adjacency list

    // Build adjacency list from edge list
    for (auto &edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Priority queue to store (weight, vertex, parent)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({0, {0, -1}});        // Start with vertex 0, weight 0, and no parent
    vector<int> key(V, INT_MAX);  // Minimum weight to each vertex
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second.first;
        int parent = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        // Print the edge included in MST
        if (parent != -1) {
            cout << parent << " <--> " << u << " --> " << weight << '\n';
        }

        // Explore neighbors
        for (auto &[v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, {v, u}});
            }
        }
    }
}

int main() {
    vector<pair<int, pair<int, int>>> edges;

    cout << "Enter Number of Vertices: \n";
    cin >> V;
    cout << "Enter Number of Edges: \n";
    cin >> E;

    cout << "Enter the graph as (u, v, w): \n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    cout << "\nMinimum Spanning Tree:\n";
    prims_algorithm(edges);

    return 0;
}
