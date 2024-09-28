#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
  int vertices;              // Number of vertices
  vector<list<int>> adjList; // Array of adjacency lists

public:
  // Constructor to initialize the graph
  Graph(int v) {
    vertices = v;
    adjList.resize(vertices);
  }

  // Function to add an edge between two vertices
  void addEdge(int src, int dest) {
    adjList[src].push_back(dest); // Add dest to src's list
    adjList[dest].push_back(
        src); // For undirected graph, add src to dest's list
  }

  // Function to remove an edge between two vertices
  void removeEdge(int src, int dest) {
    adjList[src].remove(dest);
    adjList[dest].remove(src); // For undirected graph
  }

  // Function to display the adjacency list
  void display() {
    for (int i = 0; i < vertices; ++i) {
      cout << "Vertex " << i << ":";
      for (int vertex : adjList[i]) {
        cout << " -> " << vertex;
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
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  cout << "Adjacency List:" << endl;
  g.display(); // Display the adjacency list

  return 0;
}
