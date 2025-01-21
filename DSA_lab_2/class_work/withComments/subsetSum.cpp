#include <iostream>
#include <vector>
using namespace std;

// Returns true if a subset with the given target sum exists
bool SubsetSum(int nums[], int n, int target) {
    bool table[100][100];  // DP table

    // Initialize the table
    for (int w = 0; w <= target; w++) {
        table[0][w] = false;  // No subset can form a non-zero sum with 0 elements
    }
    for (int i = 0; i <= n; i++) {
        table[i][0] = true;  // A sum of 0 can always be formed with an empty subset
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= target; w++) {
            // Check if the current element can be included in the subset
            if (nums[i] <= w) {
                table[i][w] = table[i - 1][w] || table[i - 1][w - nums[i]];
            } else {
                table[i][w] = table[i - 1][w];  // Exclude the current element
            }
        }
    }

    // Traceback to find the subset (optional)
    int i = n;
    int w = target;
    vector<int> subset;
    while (i > 0 && w > 0) {
        if (table[i][w] && !table[i - 1][w]) {
            subset.push_back(nums[i]);  // Include the current element in the subset
            w = w - nums[i];           // Reduce the target by the current element
        }
        i--;
    }

    // Print the subset
    if (!subset.empty()) {
        cout << "Subset elements that form the target sum: ";
        for (int j = subset.size() - 1; j >= 0; j--) cout << subset[j] << " ";
        cout << endl;
    }

    return table[n][target];  // Return whether the target sum is achievable
}

int main() {
    int nums[] = {0, 3, 34, 4, 12, 5, 2};  // Array of elements (0 is a dummy element for 1-based indexing)
    int n = 6;                             // Number of elements (excluding the dummy element)
    int target = 9;                        // Target sum to check

    // Check if a subset exists
    if (SubsetSum(nums, n, target)) {
        cout << "Yes, a subset with the given sum exists." << endl;
    } else {
        cout << "No, a subset with the given sum does not exist." << endl;
    }

    return 0;
}
