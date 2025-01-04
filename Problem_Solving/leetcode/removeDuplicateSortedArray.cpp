#include <iostream>
#include <vector>
using namespace std;

// Function definition
int removeDuplicates(vector<int> &nums) {
  if (nums.empty())
    return 0;

  int i = 0; // Index for the last unique element
  for (int j = 1; j < nums.size(); j++) {
    if (nums[j] != nums[i]) {
      i++;
      nums[i] = nums[j];
    }
  }
  return i + 1; // Number of unique elements
}

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  // Call the function
  int k = removeDuplicates(nums);

  // Output the result
  cout << "k = " << k << endl;
  cout << "Modified array: ";
  for (int i = 0; i < k; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
