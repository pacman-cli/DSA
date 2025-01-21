/*
 * Hall Booking Problem
 * This program implements a greedy approach to solve the hall booking problem.
 * Given a set of events with start times and durations, and a cleanup time between events,
 * it finds the maximum number of events that can be scheduled in the hall.
 * Time Complexity: O(n log n) due to sorting
 */

#include <iostream>    // Include all standard C++ libraries
#include<vector>
using namespace std;

// Structure to represent an event with its properties
struct Event {
    string clubId;          // Identifier for the club requesting the event
    int start;             // Start time of the event
    int duration;          // Duration of the event
    int finish;            // Finish time (calculated as start + duration)
};

// Custom comparison function for sorting events
// Returns true if event 'a' should be scheduled before event 'b'
bool compareByFinish(const Event &a, const Event &b) {
    if (a.finish == b.finish) {
        return a.duration < b.duration;  // If finish times are same, prefer shorter duration
                                        // This optimization helps fit more events
    }
    return a.finish < b.finish;         // Otherwise, sort by finish time
}

// Function to select maximum number of non-overlapping events
// Parameters: vector of events and cleanup time required between events
vector<Event> selectEvents(vector<Event> &events, int cleanupTime) {
    // Calculate finish time for each event by adding start time and duration
    for (auto &event : events) {
        event.finish = event.start + event.duration;
    }

    // Sort events by finish time using custom comparator
    sort(events.begin(), events.end(), compareByFinish);

    vector<Event> selected;              // Vector to store selected events
    if (events.empty()) return selected; // Return empty vector if no events

    // Always select first event (greedy choice)
    selected.push_back(events[0]);
    // Track last finish time including cleanup time
    int lastFinish = events[0].finish + cleanupTime;

    // Consider remaining events one by one
    for (int i = 1; i < events.size(); i++) {
        // If current event starts after previous event's finish time plus cleanup
        if (events[i].start >= lastFinish) {
            selected.push_back(events[i]);  // Select this event
            lastFinish = events[i].finish + cleanupTime;  // Update last finish time
        }
    }

    return selected;  // Return vector of selected events
}

int main() {
    int N;                      // Number of events
    cin >> N;

    // Read all event details
    vector<Event> events(N);    // Vector to store all events
    for (int i = 0; i < N; i++) {
        // Input format: clubId start_time duration
        cin >> events[i].clubId >> events[i].start >> events[i].duration;
    }

    int X;                      // Cleanup time required between events
    cin >> X;

    // Get the optimal schedule of events
    vector<Event> selected = selectEvents(events, X);

    // Print the selected clubs in order of their events
    cout << "Chosen clubs:\n";
    for (const Event &event : selected) {
        cout << event.clubId << "\n";
    }

    return 0;                   // End program with success status
}
