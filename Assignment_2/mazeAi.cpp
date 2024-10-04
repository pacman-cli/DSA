#include <iostream>
#include <vector>
using namespace std;

// Maze grid definition
const int ROWS = 5;
const int COLS = 5;

// Maze matrix (global variable)
int maze[ROWS][COLS] = {{0, 1, 2, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 3, 1, 0, 0},
                        {0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0}};

// Direction vectors for movement (up, down, left, right)
int dirRow[] = {-1, 1, 0, 0};
int dirCol[] = {0, 0, -1, 1};

// Utility function to check if a position is within the maze and not a wall
bool isValid(int row, int col, vector<vector<bool>> &visited) {
  return (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
          maze[row][col] != 1 && !visited[row][col]);
}

// Depth-First Search (DFS) function to find a path from start to exit (2)
bool findPathsWithTreasures(int row, int col, vector<pair<int, int>> &path,
                            vector<vector<bool>> &visited,
                            bool &foundTreasure) {
  // If the current cell is the exit, and treasure was found, print the path
  if (maze[row][col] == 2 && foundTreasure) {
    path.push_back({row, col}); // Include the exit in the path
    cout << "Path with treasure: ";
    for (const auto &p : path) {
      cout << "(" << p.first << "," << p.second << ") ";
      if (p != path.back())
        cout << "->";
    }
    cout << endl;
    return true; // A valid path is found
  }

  // Mark the current cell as visited and add it to the path
  visited[row][col] = true;
  path.push_back({row, col});

  // If the current cell contains a treasure
  if (maze[row][col] == 3) {
    foundTreasure = true;
  }

  // Explore all 4 possible directions (up, down, left, right)
  for (int i = 0; i < 4; i++) {
    int newRow = row + dirRow[i];
    int newCol = col + dirCol[i];

    // If the new position is valid and not visited yet
    if (isValid(newRow, newCol, visited)) {
      if (findPathsWithTreasures(newRow, newCol, path, visited,
                                 foundTreasure)) {
        return true;
      }
    }
  }

  // Backtrack (undo the current move)
  path.pop_back();
  visited[row][col] = false;

  return false;
}

// Function to find a path from the starting position to the exit with treasure
void findPathsWithTreasures(int start_row, int start_col) {
  vector<pair<int, int>> path;
  vector<vector<bool>> visited(
      ROWS,
      vector<bool>(COLS, false)); // Visited array to avoid revisiting cells
  bool foundTreasure = false;

  if (!findPathsWithTreasures(start_row, start_col, path, visited,
                              foundTreasure)) {
    cout << "No path with treasure found." << endl;
  }
}

int main() {
  // Example 1: Path from (0, 0)
  cout << "Starting from (0, 0):" << endl;
  findPathsWithTreasures(0, 0);

  // Example 2: Path from (1, 0)
  cout << "\nStarting from (1, 0):" << endl;
  findPathsWithTreasures(1, 0);

  return 0;
}
