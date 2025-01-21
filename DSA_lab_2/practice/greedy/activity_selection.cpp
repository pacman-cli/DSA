/*
 * Activity Selection Problem
 * This program implements the greedy approach to solve the activity selection problem.
 * It finds the maximum number of non-overlapping activities that can be performed
 * by a single person, given their start and finish times.
 */

#include <iostream>     // For input/output operations (cin, cout)
#include <vector>       // For using dynamic arrays (vector)
#include <algorithm>    // For using sort function
using namespace std;    // Using standard namespace to avoid std:: prefix

// Structure to represent an activity with its properties
struct Activity {
    int start;          // Starting time of the activity
    int finish;         // Finishing time of the activity
    int index;          // Original position/index of activity (1-based indexing)
    
    // Constructor to initialize an activity with given values
    Activity(int s, int f, int i) : start(s), finish(f), index(i) {}
};

// Custom comparison function for sorting activities
// Returns true if activity 'a' should come before activity 'b'
bool compareByFinish(const Activity& a, const Activity& b) {
    return a.finish < b.finish;  // Sort activities based on finish time in ascending order
}

// Function to select maximum number of non-overlapping activities
vector<int> selectActivities(vector<int>& start, vector<int>& finish) {
    int n = start.size();                // Get total number of activities
    vector<Activity> activities;          // Vector to store all activities
    vector<int> selected;                 // Vector to store indices of selected activities
    
    // Create Activity objects combining start time, finish time and original index
    for (int i = 0; i < n; i++) {
        activities.push_back(Activity(start[i], finish[i], i + 1));
    }
    
    // Sort all activities according to finish time using custom comparator
    sort(activities.begin(), activities.end(), compareByFinish);
    
    // Always select first activity (greedy choice)
    selected.push_back(activities[0].index);
    int lastFinish = activities[0].finish;    // Keep track of last selected activity's finish time
    
    // Iterate through remaining activities
    for (int i = 1; i < n; i++) {
        // If current activity's start time is greater than or equal to
        // the finish time of last selected activity
        if (activities[i].start >= lastFinish) {
            selected.push_back(activities[i].index);  // Select this activity
            lastFinish = activities[i].finish;        // Update last finish time
        }
    }
    
    return selected;  // Return list of selected activity indices
}

int main() {
    int n;  // Variable to store number of activities
    cout << "Enter number of activities: ";
    cin >> n;
    
    // Create vectors to store start and finish times
    vector<int> start(n), finish(n);
    
    // Input start times for all activities
    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    
    // Input finish times for all activities
    cout << "Enter finish times: ";
    for (int i = 0; i < n; i++) {
        cin >> finish[i];
    }
    
    // Get the list of selected activities using greedy approach
    vector<int> selected = selectActivities(start, finish);
    
    // Print the results
    cout << "Number of selected activities: " << selected.size() << endl;
    cout << "Selected activities: ";
    for (int index : selected) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;  // End program with success status
}
