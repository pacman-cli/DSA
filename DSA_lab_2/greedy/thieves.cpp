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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

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

// Custom comparison function for sorting items by value/weight ratio
bool compare(const Item &a, const Item &b) {
    return (a.value / a.originalWeight) > (b.value / b.originalWeight);
}

// Function to simulate one thief stealing items
double stealItems(vector<Item> &items, double capacity,
                  vector<pair<string, pair<double, double>>> &itemsTaken) {
    double totalProfit = 0.0; // Track total value stolen
    
    for (auto &item : items) {
        if (capacity <= 0) break; // Stop if capacity is full
        
        if (item.weight > 0) {    // Only consider items with remaining weight
            double fraction = min(capacity, item.weight);
            capacity -= fraction;  // Update remaining capacity
            double itemProfit = (fraction / item.originalWeight) * item.value;
            totalProfit += itemProfit;
            itemsTaken.push_back({item.name, {fraction, itemProfit}});
            item.weight -= fraction;  // Update remaining weight of item
        }
    }
    
    return totalProfit;
}

// Helper function to print a double value with one decimal precision
void printWithPrecision(double value) {
    int scaledValue = static_cast<int>(value * 10 + 0.5); // Scale and round
    cout << scaledValue / 10 << "." << scaledValue % 10;  // Print integer and decimal parts
}

int main() {
    // Input number of items in warehouse
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    // Create and populate vector of items
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        string name;
        double value, weight;
        cin >> name >> value >> weight;
        items.emplace_back(name, value, weight);
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
    
    for (int i = 0; i < K && !items.empty(); i++) {
        vector<pair<string, pair<double, double>>> itemsTaken;
        double profit = stealItems(items, capacities[i], itemsTaken);

        if (profit > 0) {
            thievesUsed++;
            totalProfit += profit;
            for (const auto &item : itemsTaken) {
                cout << "Taking " << item.first << ": ";
                printWithPrecision(item.second.first);
                cout << " kg ";
                printWithPrecision(item.second.second);
                cout << " taka\n";
            }
            cout << "Thief " << thievesUsed << " profit: ";
            printWithPrecision(profit);
            cout << " taka\n";
        }
    }

    cout << "\nTotal " << thievesUsed << " thieves stole from the warehouse.\n";

    bool hasRemaining = false;
    for (const auto &item : items) {
        if (item.weight > 0) {
            if (!hasRemaining) {
                cout << "Still following items are left:\n";
                hasRemaining = true;
            }
            double remainingProfit = (item.weight / item.originalWeight) * item.value;
            cout << item.name << " ";
            printWithPrecision(item.weight);
            cout << " kg ";
            printWithPrecision(remainingProfit);
            cout << " taka\n";
        }
    }

    return 0;  // End program with success status
}
