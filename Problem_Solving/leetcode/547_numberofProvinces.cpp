// #include <vector>
// using namespace std;
//
// class Solution {
// private:
//   void dfs(int node, vector<int> adjList[], vector<int> &visited) {
//     visited[node] = 1;
//     for (auto it : adjList[node]) {
//       if (!visited[it]) {
//         dfs(it, adjList, visited);
//       }
//     }
//   }
//
// public:
//   int numProvinces(vector<vector<int>> &adj, int V) {
//     vector<int> adjList[V];
//     for (int i = 0; i < V; i++) {
//       for (int j = 0; j < V; j++) {
//         if (adjList[i][j] == 1 && i != j) { // self nodes are not considered
//           adjList[i].push_back(j);
//           adjList[j].push_back(i);
//         }
//       }
//     }
//     vector<int> visited(V, 0);
//     int count = 0;
//     for (int i = 0; i < V; i++) {
//       if (!visited[i]) {
//         count++;
//         dfs(i, adjList, visited);
//       }
//     }
//     return count;
//   }
// };
//
// int main() {
//   vector<vector<int>> adj{{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
//   Solution ob;
//   ob.numProvinces(adj, 3);
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited) {
    visited[node] = 1;
    for (auto it : adjList[node]) {
      if (!visited[it]) {
        dfs(it, adjList, visited);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int V = isConnected.size();
    vector<vector<int>> adjList(V);

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (isConnected[i][j] == 1 && i != j) { // Exclude self-loops
          adjList[i].push_back(j);
        }
      }
    }

    // Initialize visited array
    vector<int> visited(V, 0);
    int count = 0;

    // Perform DFS to count provinces
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        count++;
        dfs(i, adjList, visited);
      }
    }

    return count;
  }
};

int main() {
  // Example 1
  vector<vector<int>> isConnected1{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  Solution ob1;
  cout << "Number of Provinces (Example 1): " << ob1.findCircleNum(isConnected1)
       << endl;

  // Example 2
  vector<vector<int>> isConnected2{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Solution ob2;
  cout << "Number of Provinces (Example 2): " << ob2.findCircleNum(isConnected2)
       << endl;

  return 0;
}
