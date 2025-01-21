/*
 * Thieves in Warehouse Problem
 * 
 * This program simulates multiple thieves stealing items from a warehouse using
 * a fractional knapsack approach. Each thief:
 * - Has a maximum weight capacity they can carry
 * - Can take fractions of items
 * - Tries to maximize the value of items taken
 * 
 * The program uses a greedy approach, where:
 * 1. Items are sorted by value/weight ratio
 * 2. Each thief takes items in order of highest value/weight ratio
 * 3. Remaining items can be taken by subsequent thieves
 * 
 * Time Complexity: O(n log n) for sorting + O(nk) for k thieves
 * Space Complexity: O(n) for storing items and results
 */

#include <iostream>      // For input/output operations (cin, cout)
#include <vector>        // For dynamic arrays (vector)
#include <algorithm>     // For sort function
#include <bits/stdc++.h> // For additional utilities (setprecision, fixed)
using namespace std;

// Structure to represent an item in the warehouse
struct Item {
    string name;          // Name/identifier of the item
    double value;         // Value of the item in currency
    double weight;        // Current weight of the item (may decrease as parts are taken)
    double originalWeight;// Original weight (needed for value calculations)
    
    // Constructor to initialize a new item
    Item(string n, double v, double w) : name(n), value(v), weight(w) {
        originalWeight = weight;  // Store original weight for later calculations
    }
};

// Custom comparison function for sorting items
// Returns true if item 'a' should be considered before item 'b'
bool compare(const Item &a, const Item &b) {
    // Sort by value per unit weight (higher ratio first)
    return (a.value / a.originalWeight) > (b.value / b.originalWeight);
}

// Function to simulate one thief stealing items
// Parameters:
// - items: Reference to vector of available items
// - capacity: Maximum weight the thief can carry
// - itemsTaken: Vector to store details of items taken
// Returns: Total value of items stolen by this thief
double stealItems(vector<Item> &items, double capacity,
                  vector<pair<string, pair<double, double>>> &itemsTaken) {
    double totalProfit = 0.0;    // Track total value stolen
    
    // Process each item in order (already sorted by value/weight ratio)
    for (auto &item : items) {
        if (capacity <= 0) break; // Stop if capacity is full
        
        if (item.weight > 0) {    // Only consider items with remaining weight
            // Calculate how much of this item we can take
            double fraction = min(capacity, item.weight);
            
            capacity -= fraction;  // Update remaining capacity
            
            // Calculate value of fraction taken (proportional to weight)
            double itemProfit = (fraction / item.originalWeight) * item.value;
            totalProfit += itemProfit;
            
            // Record what was taken (item name, weight taken, value gained)
            itemsTaken.push_back({item.name, {fraction, itemProfit}});
            
            item.weight -= fraction;  // Update remaining weight of item
        }
    }
    
    return totalProfit;
}

int main() {
    // Input number of items in warehouse
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    // Create and populate vector of items
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        // Read name, value, and weight for each item
        cin >> items[i].name >> items[i].value >> items[i].weight;
    }

    // Input number of thieves
    int K;
    cout << "Enter number of thieves: ";
    cin >> K;

    // Read weight capacity for each thief
    vector<double> capacities(K);
    for (int i = 0; i < K; i++) {
        cin >> capacities[i];
    }

    // Sort items by value/weight ratio (highest ratio first)
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;     // Track total value stolen by all thieves
    int thievesUsed = 0;          // Count thieves who successfully stole items

    cout << "\nStealing process:\n";
    
    // Process each thief in order
    for (int i = 0; i < K && !items.empty(); i++) {
        // Vector to track what this thief takes
        vector<pair<string, pair<double, double>>> itemsTaken;
        
        // Simulate this thief's stealing
        double profit = stealItems(items, capacities[i], itemsTaken);

        // If thief managed to steal anything
        if (profit > 0) {
            thievesUsed++;
            totalProfit += profit;

            // Print detailed report of items taken by this thief
            for (const auto &item : itemsTaken) {
                cout << "Taking\n"
                     << item.first << ":\n"
                     << fixed << setprecision(1) << item.second.first << " kg "
                     << fixed << setprecision(1) << item.second.second
                     << " taka\n";
            }
            cout << "Thief " << thievesUsed << " profit: " << fixed
                 << setprecision(1) << profit << " taka\n";
        }
    }

    // Print summary of theft
    cout << "\nTotal " << thievesUsed << " thieves stole from the warehouse.\n";

    // Check and report any items remaining in warehouse
    bool hasRemaining = false;
    for (const auto &item : items) {
        if (item.weight > 0) {  // If item has weight remaining
            if (!hasRemaining) {
                cout << "Still following items are left\n";
                hasRemaining = true;
            }
            // Calculate and print remaining value
            double remainingProfit = (item.weight / item.originalWeight) * item.value;
            cout << item.name << " " << fixed << setprecision(1) << item.weight
                 << " kg " << fixed << setprecision(1) << remainingProfit
                 << " taka\n";
        }
    }
    
    return 0;  // End program with success status
}
