/*
 * Fractional Knapsack Problem
 * This program implements the greedy approach to solve the fractional knapsack
 * problem. Given a set of items with weights and values, and a knapsack
 * capacity W, it finds the maximum value that can be achieved by taking
 * fractions of items. Time Complexity: O(n log n) due to sorting
 */

#include <algorithm> // For sort function
#include <iostream>  // Include all standard C++ libraries
#include <vector>    // For using dynamic arrays (vector)
using namespace std;

// Structure to represent an item with its properties
struct Item {
  int id; // Unique identifier for the item
  int w;  // Weight of the item
  int v;  // Value of the item
};

// Custom comparison function for sorting items by value per unit weight
// Returns true if item1 has better value/weight ratio than item2
bool comp(Item i1, Item i2) {
  return i1.v * 1.0 / i1.w >
         i2.v * 1.0 / i2.w; // Convert to double to avoid integer division
}

// Function to solve Fractional Knapsack problem
// Parameters: vector of items and knapsack capacity W
// Returns: maximum achievable profit
double FractionalKnapsack(vector<Item> items, int W) {
  // Sort items by value per unit weight in descending order
  sort(items.begin(), items.end(), comp);

  double profit = 0;   // Total profit accumulated
  double cap_left = W; // Remaining capacity in knapsack

  // Process each item in sorted order
  for (int i = 0; i < items.size(); i++) {
    if (cap_left <= 0)
      break; // Stop if knapsack is full

    int vi = items[i].v; // Value of current item
    int wi = items[i].w; // Weight of current item

    // Calculate fraction of item that can be taken
    // min(1.0, cap_left/wi) ensures we don't take more than 100% of item
    double fraction = min(1.0, cap_left / wi);

    cap_left -= fraction * wi; // Update remaining capacity
    profit += fraction * vi;   // Add profit from this item

    // Print details of item if any fraction was taken
    if (fraction > 0) {
      cout << "item" << items[i].id << ":" << fraction * wi << "kg"
           << fraction * vi << "taka" << endl;
    }
  }
  return profit;
}

int main() {
  int n; // Number of items
  cin >> n;

  vector<Item> items; // Vector to store all items
  int w, v;           // Temporary variables for weight and value input

  // Input weights and values for each item
  for (int i = 0; i < n; i++) {
    cin >> w >> v;                      // Read weight and value
    items.push_back(Item{i + 1, w, v}); // Add item to vector with 1-based ID
  }

  int W; // Knapsack capacity
  cin >> W;

  // Solve the problem and get maximum profit
  double result = FractionalKnapsack(items, W);

  // Print the maximum achievable profit
  cout << "Maximum profit:" << result << "taka" << endl;
  return 0; // End program with success status
}
