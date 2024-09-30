#include <iostream>
using namespace std;

// 0->we can move to that cell
// 1->obstacle
// 2->exit

int maze[5][4] =
    {0, 0, 0, 1,
     0, 1, 0, 0,
     0, 0, 0, 2,
     1, 0, 1, 0,
     0, 0, 0, 0};

int visited[5][4] = {0};

int rows = 5, columns = 4;

int reached = 0;
void findExit(int r, int c)
{
  if (r < 0 || r >= rows || c < 0 || c >= columns)
    return;
  if (reached == 1)
    return;
  cout << "(" << r << ", " << c << ")" << endl;
  visited[r][c] = 1;
  if (maze[r][c] == 2)
  {
    cout << "We have found the exit" << endl;
    reached = 1;
    return;
  }

  // up
  if (maze[r - 1][c] != 1 && visited[r - 1][c] != 1)
  {
    findExit(r - 1, c);
  }
  // right
  if (maze[r][c + 1] != 1 && visited[r][c + 1] != 1)
  {
    findExit(r, c + 1);
  }
  // down
  if (maze[r + 1][c] != 1 && visited[r + 1][c] != 1)
  {
    findExit(r + 1, c);
  }
  // left
  if (maze[r][c - 1] != 1 && visited[r][c - 1] != 1)
  {
    findExit(r, c - 1);
  }
}
int main()
{
  // source : (0,0) cell
  findExit(0, 0);
}
