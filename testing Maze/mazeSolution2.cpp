
#include <cstring>
#include <iostream>
using namespace std;

// 0 -> Pathway
// 1 -> Wall
// 2 -> Exit
// 3 -> Treasure

int maze[5][5] = {{0, 1, 0, 0, 2},
                  {0, 0, 0, 1, 0},
                  {0, 3, 1, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 0, 0, 0}};

int visited[5][5] = {0}; // Fixed the size of the visited array
int path[100][2];        // To store the path
int pathIndex = 0;
int rows = 5, columns = 5; // Fixed columns to 5
bool found = false;

void find_paths_with_treasures(int r, int c) {
  // Base case: Check for out-of-bounds, wall, or visited cell
  if (r < 0 || r >= rows || c < 0 || c >= columns || maze[r][c] == 1 ||
      visited[r][c] == 1) {
    return;
  }

  // Add the current position to the path
  path[pathIndex][0] = r;
  path[pathIndex][1] = c;
  pathIndex++;
  visited[r][c] = 1; // Mark the cell as visited

  // Check if we have reached the exit
  if (maze[r][c] == 2) {
    // Check if the path contains treasure
    bool hasTreasure = false;
    for (int i = 0; i < pathIndex; i++) {
      if (maze[path[i][0]][path[i][1]] == 3) {
        hasTreasure = true;
        break;
      }
    }

    if (hasTreasure) {
      // Print the path that includes treasure
      cout << "Path with treasure:";
      for (int i = 0; i < pathIndex; i++) {
        cout << " (" << path[i][0] << "," << path[i][1] << ")";
      }
      cout << endl;
      found = true;
    }

    // Backtrack
    pathIndex--;
    visited[r][c] = 0;
    return;
  }

  // Explore all four possible directions
  find_paths_with_treasures(r - 1, c); // up
  find_paths_with_treasures(r, c + 1); // right
  find_paths_with_treasures(r + 1, c); // down
  find_paths_with_treasures(r, c - 1); // left

  // Backtrack
  pathIndex--;
  visited[r][c] = 0;
}

int main() {
  find_paths_with_treasures(0, 0);
  if (!found) {
    cout << "No path with treasure found." << endl;
  }
  return 0;
}
