#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;

// A function to find the MST using Prim's Algorithm
void prims_algorithm(vector<pair<int, int>> adj[]) {
    // Priority queue to store (weight, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> key(V, INT_MAX);   // To store the minimum weight edge to a vertex
    vector<bool> inMST(V, false);  // To track vertices included in MST
    vector<int> parent(V, -1);     // To store the MST

    int start = 0;  // Start from vertex 0
    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;

        // Traverse adjacent vertices of the selected vertex
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If v is not in MST and weight of (u, v) is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " <--> " << i << " --> " << key[i] << '\n';
        }
    }
}

int main() {
    cout << "Enter Number of Vertices: \n";
    cin >> V;
    cout << "Enter Number of Edges: \n";
    cin >> E;

    vector<pair<int, int>> adj[V];  // Adjacency list

    cout << "Enter the graph as (u, v, w): \n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // For undirected graph
    }

    prims_algorithm(adj);

    return 0;
}
