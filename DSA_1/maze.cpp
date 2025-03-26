#include <iostream>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

int maze[5][5] = {{0, 1, 0, 0, 2},
                  {0, 0, 0, 1, 0},
                  {0, 3, 1, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 0, 0, 0}};

int visited[5][5] = {0};

string s[5][5];

void dfs(int row, int col, int search, int length) {
  // base case: check if out of bounds or hitting a wall or already visited
  if (row < 0 || row > 4 || col < 0 || col > 4 || maze[row][col] == 1 ||
      visited[row][col] == 1)
    return;

  length++; // increase path length

  // mark the current cell as visited
  visited[row][col] = 1;

  // add the current position to the path string
  s[row][col] += "( " + to_string(row) + " " + to_string(col) + " ), ";

  // check if we've found the treasure (maze[row][col] == 3)
  if (maze[row][col] == 3) {
    search = 3; // mark that treasure has been found
    if (length <= 3) {
      s[row][col] = 'y' + s[row][col]; // mark the path as a "good" one
    }
  }

  // check if we've reached the destination (maze[row][col] == 2)
  if (maze[row][col] == 2) {
    string ss = s[row][col];
    if (search == 3) { // treasure was found
      if (ss[0] == 'y') {
        cout << " Eureka and Can reach End " << nl;
      } else {
        cout << " Treasure hunt boring and Can reach End " << nl;
      }
    }
  }

  // explore neighboring cells (right, left, down, up)
  if (col + 1 <= 4 && maze[row][col + 1] != 1) {
    s[row][col + 1] = s[row][col]; // carry over the path to the next cell
    dfs(row, col + 1, search, length);
  }
  if (col - 1 >= 0 && maze[row][col - 1] != 1) {
    s[row][col - 1] = s[row][col];
    dfs(row, col - 1, search, length);
  }
  if (row + 1 <= 4 && maze[row + 1][col] != 1) {
    s[row + 1][col] = s[row][col];
    dfs(row + 1, col, search, length);
  }
  if (row - 1 >= 0 && maze[row - 1][col] != 1) {
    s[row - 1][col] = s[row][col];
    dfs(row - 1, col, search, length);
  }

  // backtrack by unmarking the cell if needed (if we want to explore other
  // paths)
  visited[row][col] = 0;
}

int main() {
  dfs(1, 0, 0, 0); // start DFS from position (1, 0)
  CRACKED;
}
