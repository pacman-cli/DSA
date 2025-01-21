/*
 * Minimum Gas Stops Problem
 * 
 * This program solves the problem of finding the minimum number of gas stops
 * needed to reach a destination. Given:
 * - A destination distance D
 * - A car that can travel at most m units with a full tank
 * - A list of gas stations and their distances from the starting point
 * 
 * Time Complexity: O(n) where n is the number of gas stations
 * Space Complexity: O(1) as we only use a constant amount of extra space
 */

#include <iostream>     // For input/output operations (cin, cout)
#include <vector>       // For dynamic arrays (vector)
#include <algorithm>    // For sort and other algorithms
using namespace std;

// Function to validate if the destination is reachable with given gas stations
// Returns true if destination can be reached, false otherwise
bool canReachDestination(int D, int m, const vector<int>& stations) {
    if (stations.empty()) {
        return m >= D;  // If no stations, we need enough fuel to reach directly
    }
    
    // Check if we can reach the first station
    if (stations[0] > m) return false;
    
    // Check if distances between consecutive stations are within tank capacity
    for (int i = 1; i < stations.size(); i++) {
        if (stations[i] - stations[i-1] > m) {
            return false;  // Can't reach next station with full tank
        }
    }
    
    // Finally, check if we can reach destination from last station
    return (D - stations.back()) <= m;
}

// Function to calculate minimum number of gas stops needed
// Parameters:
// - D: Total distance to destination
// - m: Maximum distance car can travel with full tank
// - stations: Vector of distances where gas stations are located
// Returns: Minimum number of stops needed, or -1 if destination unreachable
int minGasStops(int D, int m, const vector<int>& stations) {
    // First validate if destination is reachable at all
    if (!canReachDestination(D, m, stations)) {
        return -1;  // Destination cannot be reached with given stations
    }
    
    // Check if we can reach destination without any stops
    if (m >= D) return 0;
    
    int numStops = 0;     // Counter for number of stops made
    int currentPos = 0;   // Current position on the route
    int n = stations.size();
    
    // Continue until we reach destination
    while (currentPos < D) {
        int nextStop = -1;                    // Index of next chosen station
        int maxReach = currentPos + m;        // Maximum distance we can reach from current position
        
        // If we can reach destination from current position, we're done
        if (maxReach >= D) break;
        
        // Find the furthest reachable gas station
        // This is the greedy choice - we want to get as far as possible
        for (int i = 0; i < n && stations[i] <= maxReach; i++) {
            if (stations[i] > currentPos) {    // Only consider stations ahead of us
                nextStop = i;                  // Keep updating to get furthest station
            }
        }
        
        // If we couldn't find any reachable station
        if (nextStop == -1) return -1;        // Path to destination is blocked
        
        // Move to the selected station
        currentPos = stations[nextStop];       // Update our position
        numStops++;                           // Increment stop counter
    }
    
    return numStops;  // Return the minimum number of stops needed
}

int main() {
    // Variables for input
    int D;  // Destination distance
    int m;  // Maximum distance with full tank
    int n;  // Number of gas stations
    
    // Get destination distance and tank capacity
    cout << "Enter destination distance and tank capacity: ";
    cin >> D >> m;
    
    // Get number of gas stations
    cout << "Enter number of gas stations: ";
    cin >> n;
    
    // Create vector to store gas station locations
    vector<int> stations(n);
    
    // Input the distances of each gas station
    cout << "Enter gas station distances: ";
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }
    
    // Calculate the minimum number of stops needed
    int result = minGasStops(D, m, stations);
    
    // Output the result
    if (result == -1) {
        cout << "Can't reach destination" << endl;
    } else {
        cout << "Minimum number of stops needed: " << result << endl;
    }
    
    return 0;  // End program with success status
}
