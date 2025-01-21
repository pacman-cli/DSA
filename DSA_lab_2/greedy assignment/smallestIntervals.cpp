#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<double, double> > findUnitIntervals(vector<double>& points) {
    sort(points.begin(), points.end());

    vector<pair<double, double> > intervals;

    for (size_t i = 0; i < points.size();) {
        double start = points[i];
        double end = start + 1.0;
        intervals.emplace_back(start, end);

        while (i < points.size() && points[i] <= end) {
            i++;
        }
    }

    return intervals;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<double> points(n);

    cout << "Enter the points: ";
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    vector<pair<double, double> > intervals = findUnitIntervals(points);

    cout << "The smallest set of unit-length intervals are:\n";
    for (const auto& interval : intervals) {
        cout << "[" << interval.first << ", " << interval.second << "]\n";
    }

    return 0;
}
