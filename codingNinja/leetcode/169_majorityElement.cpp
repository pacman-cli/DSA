#include <vector>
class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int count = 0;
      int f = nums[i];

      // Count occurrences of nums[i]
      for (int j = 0; j < n; j++) {
        if (nums[j] == f) {
          count++;
        }
      }

      // Check if it is the majority element
      if (count > n / 2) {
        return f;
      }
    }

    return -1; // Return a default value
  }
};
