#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Activity {
    int start;
    int finish;
    int index;
    Activity(int s, int f, int i) : start(s), finish(f), index(i) {}
};
bool compareByFinish(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

vector<int> selectActivities(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    vector<Activity> activities;
    vector<int> selected;
    for (int i = 0; i < n; i++) {
       activities.push_back(Activity(start[i], finish[i], i + 1));
    }

    sort(activities.begin(), activities.end(), compareByFinish);

    selected.push_back(activities[0].index);
    int lastFinish = activities[0].finish;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(activities[i].index);
            lastFinish = activities[i].finish;
        }
    }

    return selected;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

   vector<int> start(n), finish(n);

    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    cout << "Enter finish times: ";
    for (int i = 0; i < n; i++) {
        cin >> finish[i];
    }

    vector<int> selected = selectActivities(start, finish);

    cout << "Number of selected activities: " << selected.size() << endl;
    cout << "Selected activities: ";
    for (int index : selected) {
        cout << index << " ";
    }
        cout << endl;

    return 0;
}
