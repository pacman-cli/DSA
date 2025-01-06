
#include <iostream>
using namespace std;

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

int visited[rows][columns] = {0};
int path[100][2]; // To store the path (row and column)
int pIdx = 0;
bool found = false;
int dfs_time = 0;

void find_paths_with_treasures(int r, int c)
{
  if (r < 0 || r >= rows || c < 0 || c >= columns || maze[r][c] == 1 ||
      visited[r][c] == 1)
  {
    return;
  }

  visited[r][c] = 1;
  path[pIdx][0] = r;
  path[pIdx][1] = c;
  pIdx++;
  dfs_time++;

  if (maze[r][c] == 2)
  {
    bool foundTresure = false;
    for (int i = 0; i < pIdx; i++)
    {
      if (maze[path[i][0]][path[i][1]] == 3)
      {
        foundTresure = true;
        break;
      }
    }

    // print path
    if (foundTresure)
    {
      cout << "Path with treasure: ";
      for (int i = 0; i < pIdx; i++)
      {
        cout << "(" << path[i][0] << "," << path[i][1] << ")";
        if (i != pIdx - 1)
          cout << "->";
      }
      cout << endl;
      found = true;
    }

    // backtrack after checking the path
    pIdx--;
    visited[r][c] = 0;
    return;
  }

  find_paths_with_treasures(r - 1, c); // up
  find_paths_with_treasures(r + 1, c); // down
  find_paths_with_treasures(r, c - 1); // left
  find_paths_with_treasures(r, c + 1); // right
  // backtrack after exploring all directions
  pIdx--;
  visited[r][c] = 0;
}

int main()
{
  find_paths_with_treasures(0, 0);

  if (!found)
  {
    cout << "No path with treasure found." << endl;
  }

  return 0;
}
