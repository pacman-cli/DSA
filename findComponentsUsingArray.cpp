#include <climits>
#include <iostream>
using namespace std;

#define white 1
#define gray 2
#define black 3
#define inf INT_MAX

class Graph {
  int nVertices;
  int **matrix;
  bool directed;           // directed->true, undirected->false
  int *color, *d, *parent; // distance
  int **components;        // Dynamically allocated array of components
  int *componentSizes;     // Store sizes of each component
  int componentCount;      // Total number of components

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

    // Initialize components array to hold a maximum of n components
    components = new int *[n];
    componentSizes = new int[n]; // Array to store size of each component
    componentCount = 0;
  }

  // ~Graph() {
  //   // Free memory allocated for the matrix
  //   for (int i = 0; i < nVertices; i++) {
  //     delete[] matrix[i];
  //   }
  //   delete[] matrix;

  //   // Free memory allocated for the components
  //   for (int i = 0; i < componentCount; i++) {
  //     delete[] components[i];
  //   }
  //   delete[] components;
  //   delete[] componentSizes;

  //   // Free other dynamically allocated memory
  //   delete[] color;
  //   delete[] d;
  //   delete[] parent;
  // }

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

  void DFSUtil(int u, int *component, int &index) {
    color[u] = gray;
    component[index++] = u; // Add current vertex to the component

    for (int v = 0; v < nVertices; v++) {
      if (isEdge(u, v) && color[v] == white) {
        DFSUtil(v, component, index);
      }
    }
    color[u] = black;
  }

  void findComponents() {
    for (int i = 0; i < nVertices; i++) {
      color[i] = white;
    }

    componentCount = 0;

    for (int i = 0; i < nVertices; i++) {
      if (color[i] == white) {
        // Dynamically allocate memory for the current component
        int *component = new int[nVertices];
        int index = 0;

        DFSUtil(i, component, index);

        // Store the component and its size
        components[componentCount] = component;
        componentSizes[componentCount] = index;
        componentCount++;
      }
    }

    // Output the number of components
    cout << "Number of components: " << componentCount << endl;

    // Print each component
    for (int i = 0; i < componentCount; i++) {
      cout << "Component " << i + 1 << ": ";
      for (int j = 0; j < componentSizes[i]; j++) {
        cout << components[i][j] << " ";
      }
      cout << endl;
    }
  }
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
