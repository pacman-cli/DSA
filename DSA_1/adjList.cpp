#include <iostream>
using namespace std;

struct node {
  int value;
  node *next;
};

struct node *createNewnode(int x) {
  struct node *newnode = new node();
  newnode->value = x;
  newnode->next = NULL;
  return newnode;
}

class Graph {
  int nVertices;
  bool directed;
  struct node **adjList;

public:
  Graph(int n, bool dir) {
    nVertices = n;
    directed = dir;

    adjList = new node *[n];
    for (int i = 0; i < nVertices; i++) {
      adjList[i] = NULL;
    }
  }

  void addEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return;

    struct node *newnode = createNewnode(v);
    // check if list of u is empty
    if (adjList[u] == NULL) {
      adjList[u] = newnode;
    } else {
      newnode->next = adjList[u];
      adjList[u] = newnode;
    }

    if (!directed) {
      // add u to the list of v
      node *newnode1 = createNewnode(u);
      // check if list of v is empty
      if (adjList[v] == NULL) {
        adjList[v] = newnode1;
      } else {
        newnode1->next = adjList[v];
        adjList[v] = newnode1;
      }
    }
  }
  void display() {
    cout << "Displaying list:" << endl;

    for (int u = 0; u < nVertices; u++) {
      cout << u << " : ";
      node *current = adjList[u];
      while (current != NULL) {
        cout << current->value << ", ";
        current = current->next;
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g(5, false);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.display();
}
