#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;  // Number of vertices and edges

vector<pair<int, pair<int, int>>> edges;  // Edge list to store (weight, (u, v))
int key[100], parent[100];  // key array stores minimum edge weight, parent stores MST structure
bool inMST[100];            // Boolean array to track vertices included in MST

// Function to initialize sets for Prim's algorithm
void make_set() {
    fill(key, key + V, INT_MAX);    // Initialize all keys to infinity
    fill(inMST, inMST + V, false);  // Mark all vertices as not yet included in MST
    fill(parent, parent + V, -1);   // Initialize parent array with -1
    key[0] = 0;                     // Start from vertex 0 (arbitrary choice)
}

// Function implementing Prim's algorithm
void prims_algorithm() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // Min-heap (weight, vertex) with the starting vertex (0,0)

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the minimum key value
        pq.pop();

        if (inMST[u]) continue;  // If already in MST, skip
        inMST[u] = true;         // Mark as included in MST

        if (parent[u] != -1) {  // Print the edge forming the MST
            cout << parent[u] << " <--> " << u << " --> " << key[u] << '\n';
        }

        // Iterate through all edges to update adjacent vertices
        for (auto &edge : edges) {
            int w = edge.first;           // Edge weight
            int v1 = edge.second.first;   // First vertex of the edge
            int v2 = edge.second.second;  // Second vertex of the edge

            // If v2 is adjacent to u and is not in MST, update if weight is smaller
            if (v1 == u && !inMST[v2] && w < key[v2]) {
                key[v2] = w;
                parent[v2] = u;
                pq.push({w, v2});
            }
            // If v1 is adjacent to u and is not in MST, update if weight is smaller
            else if (v2 == u && !inMST[v1] && w < key[v1]) {
                key[v1] = w;
                parent[v1] = u;
                pq.push({w, v1});
            }
        }
    }
}

int main() {
    cout << "Enter Number of Vertices: \n";
    cin >> V;
    cout << "Enter Number of Edges: \n";
    cin >> E;

    cout << "Enter the graph as (u, v, w): \n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;            // Read edge (u, v) with weight w
        edges.push_back({w, {u, v}});  // Store edge in edge list
    }

    make_set();  // Initialize MST-related arrays

    cout << "\nMinimum Spanning Tree:\n";
    prims_algorithm();  // Execute Prim's algorithm

    return 0;
}
