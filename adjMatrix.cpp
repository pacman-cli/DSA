#include <iostream>
using namespace std;

class Graph {
  int nVertices; // Number of vertices in the graph
  int **matrix;  // 2D array to represent the adjacency matrix
  bool directed; // Boolean to check if the graph is directed or undirected

public:
  // Constructor to initialize the graph
  Graph(int n, bool dir) {
    nVertices = n;  // Set the number of vertices
    directed = dir; // Set whether the graph is directed or undirected
    matrix = new int
        *[n]; // Create an array of pointers (for each row in the matrix)

    // Create n rows, each having n columns, and initialize the matrix
    for (int i = 0; i < n; i++)
      matrix[i] =
          new int[n]; // Each row points to an array of size n (for columns)

    // Initialize all cells in the matrix to 0 (no edges initially)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] =
            0; // Set matrix[i][j] to 0 (no edge between vertices i and j)
      }
    }
  }

  // Method to add an edge between two vertices u and v
  void addEdge(int u, int v) {
    // Check for invalid vertices (negative or out of bounds)
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return; // If invalid, return without adding the edge

    matrix[u][v] = 1;   // Set matrix[u][v] to 1 (edge from u to v)
    if (!directed)      // If the graph is undirected
      matrix[v][u] = 1; // Also set matrix[v][u] to 1 (edge from v to u)
  }

  // Method to check if there's an edge between two vertices u and v
  bool isEdge(int u, int v) {
    // Check for invalid vertices
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return false; // If invalid, return false (no edge)

    // If matrix[u][v] is 1, return true (edge exists), otherwise false
    if (matrix[u][v] == 1)
      return true;
    else
      return false;
  }

  // Method to display the adjacency list representation of the graph
  void display() {
    cout << "Displaying Graph:" << endl;
    // Loop through all vertices
    for (int u = 0; u < nVertices; u++) {
      cout << u << " : "; // Print the vertex u
      // Loop through all other vertices to check if there's an edge
      for (int v = 0; v < nVertices; v++) {
        if (isEdge(u, v)) {  // If an edge exists from u to v
          cout << v << ", "; // Print vertex v
        }
      }
      cout << endl; // Move to the next line for the next vertex
    }
  }
};

int main() {
  Graph g(5, false); // Create an undirected graph with 5 vertices

  // Add edges between the specified vertices
  g.addEdge(0, 1); // Add edge between vertex 0 and 1
  g.addEdge(0, 2); // Add edge between vertex 0 and 2
  g.addEdge(0, 3); // Add edge between vertex 0 and 3
  g.addEdge(1, 3); // Add edge between vertex 1 and 3
  g.addEdge(1, 4); // Add edge between vertex 1 and 4
  g.addEdge(2, 3); // Add edge between vertex 2 and 3
  g.addEdge(3, 4); // Add edge between vertex 3 and 4

  g.display(); // Display the graph in adjacency list form
}
