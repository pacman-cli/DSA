#include <iostream>
#define CRACKED return 0;
#define nl "\n"
using namespace std;

int maze[5][5] = {{0, 1, 2, 0, 0},
                  {0, 0, 0, 1, 0},
                  {0, 3, 1, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 0, 0, 0}};

int visited[5][5] = {
    0};             // Visited array to track the cells we have already visited
int N = 5;          // Size of the maze
int path[25][2];    // To store the path (maximum length is N*N)
int pathLength = 0; // Current length of the path
bool foundTreasure = false; // To track if a treasure has been found
bool foundExit = false;     // To track if the exit has been reached

// Function to print the path
void printPath() {
  cout << "Path with treasure: ";
  for (int i = 0; i < pathLength; i++) {
    cout << "(" << path[i][0] << "," << path[i][1] << ")";
    if (i != pathLength - 1)
      cout << "->";
  }
  cout << nl;
}

// DFS function to explore the maze
void dfs(int row, int col) {
  // Boundary and wall check
  if (row < 0 || row >= N || col < 0 || col >= N || visited[row][col] == 1 ||
      maze[row][col] == 1)
    return;

  // Mark current cell as visited and add to the path
  visited[row][col] = 1;
  path[pathLength][0] = row;
  path[pathLength][1] = col;
  pathLength++;

  // If a treasure is found, set the flag
  if (maze[row][col] == 3) {
    foundTreasure = true;
  }

  // If the exit is found and treasure has been collected, print the path and
  // stop
  if (maze[row][col] == 2 && foundTreasure) {
    foundExit = true;
    printPath();
    visited[row][col] = 0;
    pathLength--;
    return;
  }

  // Explore in all four directions (right, left, down, up)
  if (!foundExit)
    dfs(row, col + 1); // Right
  if (!foundExit)
    dfs(row, col - 1); // Left
  if (!foundExit)
    dfs(row + 1, col); // Down
  if (!foundExit)
    dfs(row - 1, col); // Up

  // Backtrack: unmark the current cell as visited and remove from path
  visited[row][col] = 0;
  pathLength--;
}

// Function to find paths containing treasures from the start position
void find_paths_with_treasures(int start_row, int start_col) {
  dfs(start_row, start_col);

  if (!foundExit) {
    cout << "No path with treasure found!" << nl;
  }
}

int main() {
  int start_row, start_col;

  // Input the starting position
  cout << "Give starting position [row and column]: ";
  cin >> start_row >> start_col;
  cout << nl;

  // Find paths from the given starting position
  find_paths_with_treasures(start_row, start_col);

  CRACKED;
}
