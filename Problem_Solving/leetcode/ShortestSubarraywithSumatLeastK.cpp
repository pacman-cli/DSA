#include <climits>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<long long> prefixSum(n + 1, 0);

    // Calculate prefix sums
    for (int i = 0; i < n; ++i) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // Deque to store indices of prefix sums
    deque<int> dq;
    int minLength = INT_MAX;

    for (int i = 0; i <= n; ++i) {
      // Maintain deque such that the current prefix sum satisfies the condition
      while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
        minLength = min(minLength, i - dq.front());
        dq.pop_front();
      }

      // Maintain deque in increasing order of prefix sums
      while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    return (minLength == INT_MAX) ? -1 : minLength;
  }
};
