
#include <vector>
using namespace std;

class Solution {
public:
  int countValidSelections(vector<int> &nums) {
    int n = nums.size();
    int validSelections = 0;

    // Helper function to simulate the process
    auto isValid = [&](int start, int direction) {
      vector<int> temp = nums; // Work on a copy of nums
      int curr = start;

      while (curr >= 0 && curr < n) {
        if (temp[curr] == 0) {
          curr += direction; // Move in the current direction
        } else {
          temp[curr]--;           // Decrement the current value
          direction = -direction; // Reverse the direction
          curr += direction;      // Move in the new direction
        }
      }
      // Check if all elements are zero
      for (int x : temp) {
        if (x != 0)
          return false;
      }
      return true;
    };

    // Try all starting positions with value 0
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        // Simulate for both directions
        bool leftValid = isValid(i, -1);
        bool rightValid = isValid(i, 1);

        // Count each valid starting direction separately
        if (leftValid)
          validSelections++;
        if (rightValid)
          validSelections++;
      }
    }

    return validSelections;
  }
};
