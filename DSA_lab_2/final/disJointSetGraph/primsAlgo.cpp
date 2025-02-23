#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int V, E;

void prims_algorithm(vector<pair<int, pair<int, int>>> &edges) {
    vector<bool> inMST(V, false);       // To track vertices included in MST
    vector<int> minWeight(V, INT_MAX);  // Minimum weight to each vertex
    vector<int> parent(V, -1);          // To store the MST

    int start = 0;  // Start from vertex 0
    minWeight[start] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;

        // Find the vertex not in MST with the smallest weight
        for (int j = 0; j < V; j++) {
            if (!inMST[j] && (u == -1 || minWeight[j] < minWeight[u])) {
                u = j;
            }
        }

        if (minWeight[u] == INT_MAX) {
            cout << "Graph is not connected.\n";
            return;
        }

        inMST[u] = true;

        // Print the edge added to the MST
        if (parent[u] != -1) {
            cout << parent[u] << " <--> " << u << " --> " << minWeight[u] << '\n';
        }

        // Update weights of edges connected to the newly included vertex
        for (auto &edge : edges) {
            int w = edge.first;
            int v1 = edge.second.first;
            int v2 = edge.second.second;

            if (v1 == u && !inMST[v2] && w < minWeight[v2]) {
                minWeight[v2] = w;
                parent[v2] = u;
            } else if (v2 == u && !inMST[v1] && w < minWeight[v1]) {
                minWeight[v1] = w;
                parent[v1] = u;
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
