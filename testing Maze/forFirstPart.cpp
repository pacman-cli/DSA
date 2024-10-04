
#include <cstring>
#include <iostream>
using namespace std;

// 0 -> Pathway
// 1 -> Wall
// 2 -> Exit
// 3 -> Treasure

int maze[5][5] = {{0, 1, 2, 0, 0},
                  {0, 0, 0, 1, 0},
                  {0, 3, 1, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 0, 0, 0}};

int visited[5][5] = {0}; // To track visited cells
int path[100][2];        // To store the path
int pathIndex = 0;
int rows = 5, columns = 5; // Dimensions of the maze
bool found = false;

void find_paths_with_treasures(int r, int c)
{
  // Check for out-of-bounds or invalid cells
  if (r < 0 || r >= rows || c < 0 || c >= columns || maze[r][c] == 1 ||
      visited[r][c] == 1)
  {
    return;
  }

  // Record the current position in the path
  path[pathIndex][0] = r;
  path[pathIndex][1] = c;
  pathIndex++;
  visited[r][c] = 1; // Mark the cell as visited

  // Check if we've reached the exit
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
    if (hasTreasure)
    {
      cout << "Path with treasure:";
      for (int i = 0; i < pathIndex; i++)
      {
        cout << " (" << path[i][0] << "," << path[i][1] << ")";
        if (i < pathIndex - 1)
        {
          cout << " ->";
        }
      }
      cout << endl;
      found = true;
    }
    pathIndex--;
    visited[r][c] = 0; // Unmark the cell for other paths
    return;
  }
  // Explore all four possible directions
  find_paths_with_treasures(r - 1, c); // up
  find_paths_with_treasures(r, c + 1); // right
  find_paths_with_treasures(r + 1, c); // down
  find_paths_with_treasures(r, c - 1); // left

  // Backtrack
  pathIndex--;
  visited[r][c] = 0; // Unmark the cell for other paths
}

int main()
{
  find_paths_with_treasures(1, 0);
  if (!found)
  {
    cout << "No path with treasure found." << endl;
  }
  return 0;
}
