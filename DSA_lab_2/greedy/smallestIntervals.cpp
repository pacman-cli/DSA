#include <iostream> // For input and output operations
#include <vector>   // For using dynamic arrays (vectors)
#include <algorithm> // For using sorting function

using namespace std;

// Function to find the smallest set of unit-length closed intervals
vector<pair<double, double> > findUnitIntervals(vector<double>& points) {
    // Step 1: Sort the points in ascending order
    // This ensures we process the points from left to right
    sort(points.begin(), points.end());

    vector<pair<double, double> > intervals; // To store the selected intervals

    // Step 2: Iterate over the sorted points
    for (size_t i = 0; i < points.size();) {
        // Select the current point as the start of a new interval
        double start = points[i];
        // Define the end of the interval (unit length means +1.0)
        double end = start + 1.0;
        // Add the interval to the result list
        intervals.emplace_back(start, end);

        // Step 3: Skip all points covered by the current interval
        // Move the index forward until we find a point beyond this interval
        while (i < points.size() && points[i] <= end) {
            i++;
        }
    }

    return intervals; // Return the list of selected intervals
}

int main() {
    int n; // Variable to store the number of points
    cout << "Enter the number of points: ";
    cin >> n;

    vector<double> points(n); // Vector to store the input points

    // Step 4: Input the points from the user
    cout << "Enter the points: ";
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    // Step 5: Call the function to get the smallest set of unit-length intervals
    vector<pair<double, double> > intervals = findUnitIntervals(points);

    // Step 6: Output the result intervals
    cout << "The smallest set of unit-length intervals are:\n";
    for (const auto& interval : intervals) {
        // Print each interval in the format [start, end]
        cout << "[" << interval.first << ", " << interval.second << "]\n";
    }

    return 0; // End of the program successfully
}
