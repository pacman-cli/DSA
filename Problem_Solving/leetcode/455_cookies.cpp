#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    int n = g.size();
    int m = s.size();

    int i = 0; // child
    int j = 0; // cookie

    while (i < n && j < m) {
      if (g[i] <= s[j]) {
        i++;
      }
      j++;
    }
    return i;
  }
};
