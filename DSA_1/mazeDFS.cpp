#include <iostream>
using namespace std;

// Constants for the maze representation
const int rows = 5, columns = 5;

// Maze representation
// 0 -> Pathway
// 1 -> Wall
// 2 -> Exit
// 3 -> Treasure
int maze[rows][columns] = {{0, 1, 2, 0, 0},
                           {0, 0, 0, 1, 0},
                           {0, 3, 1, 0, 0},
                           {0, 1, 0, 1, 0},
                           {0, 0, 0, 0, 0}};

// Visited array and parent tracking
int visited[rows][columns] = {0};
int path[100][2]; // To store the path (row and column)
int pathIndex = 0;
bool found = false;
int dfs_time = 0; // Timer for DFS, renamed from "time" to avoid conflicts

// DFS function to explore the maze and find paths with treasures
void find_paths_with_treasures(int r, int c)
{
  if (r < 0 || r >= rows || c < 0 || c >= columns || maze[r][c] == 1 ||
      visited[r][c] == 1)
  {
    return;
  }

  // Mark the current cell as visited and add it to the path
  visited[r][c] = 1;
  path[pathIndex][0] = r;
  path[pathIndex][1] = c;
  pathIndex++;
  dfs_time++; // Increment DFS time

  // If we reach the exit (2), check if the path contains any treasure (3)
  if (maze[r][c] == 2)
  {
    bool hasTreasure = false;
    for (int i = 0; i < pathIndex; i++)
    {
      if (maze[path[i][0]][path[i][1]] == 3)
      {
        hasTreasure = true;
        break;
      }
    }

    // Print the path if it contains treasure
    if (hasTreasure)
    {
      cout << "Path with treasure: ";
      for (int i = 0; i < pathIndex; i++)
      {
        cout << "(" << path[i][0] << "," << path[i][1] << ")";
        if (i != pathIndex - 1)
          cout << "->";
      }
      cout << endl;
      found = true;
    }

    // Backtrack after checking the path
    pathIndex--;
    visited[r][c] = 0;
    return;
  }

  // Explore all four directions (up, right, down, left) using DFS
  find_paths_with_treasures(r - 1, c); // up
  find_paths_with_treasures(r, c + 1); // right
  find_paths_with_treasures(r + 1, c); // down
  find_paths_with_treasures(r, c - 1); // left

  // Backtrack after exploring all directions
  pathIndex--;
  visited[r][c] = 0;
}

int main()
{
  // Start DFS from the given starting point (0, 0)
  find_paths_with_treasures(0, 0);

  if (!found)
  {
    cout << "No path with treasure found." << endl;
  }

  return 0;
}
