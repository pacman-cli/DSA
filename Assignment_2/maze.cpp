#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

int N;
int pathLength = -1;

class Path {
public:
  int x, y;
};

Path path[25];
int shortestPath = INT_MAX;
string shortestPathStr = "";
string currentPathStr = "";

void findPath() {
  currentPathStr = "";

  // Construct current path string
  for (int i = 0; i <= pathLength; i++) {
    currentPathStr +=
        "(" + to_string(path[i].x) + "," + to_string(path[i].y) + ")";
    if (i < pathLength) {
      currentPathStr += " -> ";
    }
  }

  // Print the current path
  cout << "Path with treasure: " << currentPathStr << nl;

  // If this path is shorter than the previously found shortest path, update it
  if (pathLength + 1 < shortestPath) {
    shortestPath = pathLength + 1;
    shortestPathStr = currentPathStr;
  }
}

int visited[100][100] = {0};
bool inHandTreasure = false;

void dfs(int maze[100][100], int row, int col) {
  // Base cases for out-of-boundary and visiting already visited cells
  if (row < 0 || row >= N || col < 0 || col >= N || visited[row][col] ||
      maze[row][col] == 1) {
    return;
  }

  // Mark the current position as visited and add it to the current path
  pathLength++;
  visited[row][col] = 1;
  path[pathLength].x = row;
  path[pathLength].y = col;

  // If we find treasure, mark it
  if (maze[row][col] == 3) {
    inHandTreasure = true;
  }

  // If we find the exit and have collected treasure, print the path
  if (maze[row][col] == 2) {
    if (inHandTreasure) {
      findPath();
    }
  } else {
    // Explore all four possible directions: right, left, down, and up
    dfs(maze, row, col + 1); // Right
    dfs(maze, row, col - 1); // Left
    dfs(maze, row + 1, col); // Down
    dfs(maze, row - 1, col); // Up
  }

  // Backtrack: undo the current move
  if (maze[row][col] == 3) {
    inHandTreasure = false;
  }
  visited[row][col] = 0;
  pathLength--;
}

void find_paths_with_treasures(int maze[100][100], int start_row,
                               int start_col) {
  dfs(maze, start_row,
      start_col); // Searching for paths from the start position
}

int main() {
  cout << "Give maze size: ";
  cin >> N;
  int maze[100][100];

  cout << "Give maze elements: ";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maze[i][j];
    }
  }

  cout << "Give starting position [row and column]: ";
  int start_row, start_col;
  cin >> start_row >> start_col;
  cout << nl;

  find_paths_with_treasures(maze, start_row, start_col);

  if (shortestPath == INT_MAX) {
    cout << "No path with treasure found!" << nl;
  } else {
    cout << nl;
    cout << "Shortest path: " << shortestPathStr << nl;
  }

  CRACKED;
}
