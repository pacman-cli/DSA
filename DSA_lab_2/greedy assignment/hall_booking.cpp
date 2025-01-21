#include <iostream>
#include <vector>
using namespace std;

struct Event {
    string clubId;
    int start;
    int duration;
    int finish;
};

bool compareByFinish(const Event &a, const Event &b) {
    if (a.finish == b.finish) {
        return a.duration < b.duration;
    }
    return a.finish < b.finish;
}

vector<Event> selectEvents(vector<Event> &events, int cleanupTime) {
    for (auto &event : events) {
        event.finish = event.start + event.duration;
    }

    sort(events.begin(), events.end(), compareByFinish);

    vector<Event> selected;
    if (events.empty()) return selected;

    selected.push_back(events[0]);
    int lastFinish = events[0].finish + cleanupTime;

    for (int i = 1; i < events.size(); i++) {
        if (events[i].start >= lastFinish) {
            selected.push_back(events[i]);
            lastFinish = events[i].finish + cleanupTime;
        }
    }

    return selected;
}

int main() {
    int N;
    cin >> N;

    vector<Event> events(N);
    for (int i = 0; i < N; i++) {
        cin >> events[i].clubId >> events[i].start >> events[i].duration;
    }

    int X;
    cin >> X;

    vector<Event> selected = selectEvents(events, X);

    cout << "Chosen clubs:\n";
    for (const Event &event : selected) {
        cout << event.clubId << "\n";
    }

    return 0;
}
