#include <iostream>
#include <stack>
using namespace std;

#define white 1
#define gray 2
#define black 3

class Graph
{
  int nVertices;
  int **matrix;
  bool directed; // directed->true, undirected->false
  int *color, *d, *parent;
  int *start, *finish, time;

public:
  Graph(int n, bool dir)
  {
    nVertices = n;
    directed = dir;
    matrix = new int *[n]; // stores the address of each row
    for (int i = 0; i < n; i++)
      matrix[i] = new int[n]; // each row contains n integers
    // initialize all cells with 0
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        matrix[i][j] = 0;
      }
    }
    color = new int[n];
    d = new int[n];
    parent = new int[n];
    start = new int[n];
    finish = new int[n];
    time = 0;
    for (int i = 0; i < nVertices; i++)
    {
      parent[i] = -1;
    }
  }

  void addEdge(int u, int v)
  {
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return;

    matrix[u][v] = 1;
    if (!directed)
      matrix[v][u] = 1;
  }

  bool isEdge(int u, int v)
  {
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return false;
    if (matrix[u][v] == 1)
      return true;
    else
      return false;
  }

  void display()
  {
    cout << "Displaying Graph:" << endl;
    for (int u = 0; u < nVertices; u++)
    {
      cout << u << " : ";
      for (int v = 0; v < nVertices; v++)
      {
        if (isEdge(u, v))
        {
          cout << v << ", ";
        }
      }
      cout << endl;
    }
  }

  // This function will print path from source to destination
  void printPath(int src, int dest)
  {
    int d = dest;
    stack<int> s;
    while (d != -1)
    {
      s.push(d);
      d = parent[d];
    }
    cout << "Printing path" << "(" << src << "," << dest << "):";
    while (!s.empty())
    {
      d = s.top();
      s.pop();
      cout << d;
      if (!s.empty())
      {
        cout << "->";
      }
    }
    cout << endl;
  }

  void DFS()
  {
    for (int u = 0; u < nVertices; u++)
    {
      parent[u] = -1;
      color[u] = white;
    }
    time = 0;
    for (int u = 0; u < nVertices; u++)
    {
      if (color[u] == white)
      {
        DFS_visit(u);
      }
    }

    cout << "Vertex\tStart\tFinish" << endl;
    for (int u = 0; u < nVertices; u++)
    {
      cout << u << "\t" << start[u] << "\t" << finish[u] << endl;
    }
  }

  void DFS_visit(int u)
  {
    color[u] = gray;
    time += 1;
    start[u] = time;
    for (int v = 0; v < nVertices; v++)
    {
      if (matrix[u][v] == 1 && color[v] == white)
      {
        parent[v] = u;
        DFS_visit(v);
      }
    }
    color[u] = black;
    time += 1;
    finish[u] = time;
  }
};

int main()
{
  Graph g(9, false);

  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.addEdge(2, 3);
  g.addEdge(5, 4);
  // g.printPath(0, 8);
  // g.printPath(0, 5);
  g.addEdge(6, 7);
  g.addEdge(6, 8);
  g.display();

  g.DFS();
  g.printPath(0, 4); // Example of printing path from 0 to 4
}
