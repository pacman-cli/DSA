#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define white 1
#define gray 2
#define black 3
#define inf INT_MAX

class Graph {
  int nVertices;
  int **matrix;
  bool directed;                  // directed->true, undirected->false
  int *color, *d, *parent;        // distance
  vector<vector<int>> components; // To store all components

public:
  Graph(int n, bool dir) {
    nVertices = n;
    directed = dir;
    matrix = new int *[n]; // stores the address of each row
    for (int i = 0; i < n; i++)
      matrix[i] = new int[n]; // each row contains n integers
    // initialize all cells with 0
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
    color = new int[n];
    d = new int[n];
    parent = new int[n];
  }

  void addEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= nVertices ||
        v >= nVertices) // check if edge is valid
      return;

    matrix[u][v] = 1;
    if (!directed)
      matrix[v][u] = 1;
  }

  bool isEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return false;
    return matrix[u][v] == 1;
  }

  void display() {
    cout << "Displaying Graph:" << endl;
    for (int u = 0; u < nVertices; u++) {
      cout << u << " : ";
      for (int v = 0; v < nVertices; v++) {
        if (isEdge(u, v)) {
          cout << v << ", ";
        }
      }
      cout << endl;
    }
  }

  void BFS(int src) {
    for (int i = 0; i < nVertices; i++) {
      color[i] = white;
      d[i] = inf;
      parent[i] = -1;
    }
    d[src] = 0;
    color[src] = gray;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 0; v < nVertices; v++) {
        if (isEdge(u, v) && color[v] == white) {
          q.push(v);
          parent[v] = u;
          d[v] = d[u] + 1;
          color[v] = gray;
        }
      }
      color[u] = black;
    }
  }

  void DFSUtil(int u, vector<int> &component) {
    color[u] = gray;
    component.push_back(u); // Add current vertex to the component

    for (int v = 0; v < nVertices; v++) {
      if (isEdge(u, v) && color[v] == white) {
        DFSUtil(v, component);
      }
    }
    color[u] = black;
  }

  void findComponents() {
    for (int i = 0; i < nVertices; i++) {
      color[i] = white;
    }

    int componentCount = 0;

    for (int i = 0; i < nVertices; i++) {
      if (color[i] == white) {
        vector<int> component;
        DFSUtil(i, component);
        components.push_back(component);
        componentCount++;
      }
    }

    cout << "Number of components: " << componentCount << endl;

    // Print each component
    for (int i = 0; i < components.size(); i++) {
      cout << "Component " << i + 1 << ": ";
      for (int v : components[i]) {
        cout << v << " ";
      }
      cout << endl;
    }
  }

  // Other methods (BFS, printPath, etc.) remain unchanged...
};

int main() {
  Graph g(9, false); // 9 vertices and undirected graph

  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(5, 4);
  g.addEdge(6, 7);
  g.addEdge(6, 8);

  g.findComponents(); // Find and print components

  return 0;
}
