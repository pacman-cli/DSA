#include <iostream>
#include <vector>
using namespace std;

class Graph {
  int vertices;                  // Number of vertices
  vector<vector<int>> adjMatrix; // Adjacency matrix

public:
  // Constructor to initialize the graph
  Graph(int v) {
    vertices = v;
    adjMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
  }

  // Function to add an edge between two vertices
  void addEdge(int i, int j) {
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1; // For undirected graph
  }

  // Function to remove an edge between two vertices
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0; // For undirected graph
  }

  // Function to display the adjacency matrix
  void display() {
    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        cout << adjMatrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g(5); // Create a graph with 5 vertices

  // Add edges between vertices
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  cout << "Adjacency Matrix:" << endl;
  g.display(); // Display the adjacency matrix

  return 0;
}
