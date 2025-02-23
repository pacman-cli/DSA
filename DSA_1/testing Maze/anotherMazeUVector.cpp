#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// 0 -> Pathway
// 1 -> Wall
// 2 -> Exit
// 3 -> Treasure

int maze[5][4] = {
    {0, 0, 3, 1},
    {0, 1, 0, 0},
    {0, 0, 0, 2},
    {1, 0, 1, 0},
    {0, 0, 0, 0}};

int visited[5][4] = {0};
int rows = 5, columns = 4;
bool found = false;

void find_paths_with_treasures(int r, int c, vector<pair<int, int>> &path)
{
  if (r < 0 || r >= rows || c < 0 || c >= columns || maze[r][c] == 1 ||
      visited[r][c] == 1)
  {
    return;
  }

  path.push_back({r, c});
  visited[r][c] = 1;

  if (maze[r][c] == 2)
  {
    bool hasTreasure = false;
    for (auto &p : path)
    {
      if (maze[p.first][p.second] == 3)
      {
        hasTreasure = true;
        break;
      }
    }
    if (hasTreasure)
    {
      cout << "Path with treasure:";
      for (auto &p : path)
      {
        cout << " (" << p.first << "," << p.second << ")";
      }
      cout << endl;
      found = true;
    }
    path.pop_back();
    visited[r][c] = 0;
    return;
  }

  // Explore all four possible directions
  find_paths_with_treasures(r - 1, c, path); // up
  find_paths_with_treasures(r, c + 1, path); // right
  find_paths_with_treasures(r + 1, c, path); // down
  find_paths_with_treasures(r, c - 1, path); // left

  path.pop_back();
  visited[r][c] = 0;
}

int main()
{
  vector<pair<int, int>> path;
  find_paths_with_treasures(0, 0, path);
  if (!found)
  {
    cout << "No path with treasure found." << endl;
  }
  return 0;
}
