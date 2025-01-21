#include <iostream>
#include <vector>
using namespace std;

int main() {
    int D, m, n;
    cin >> D >> m >> n;

    vector<int> gas_stations(n);
    for (int i = 0; i < n; ++i) {
        cin >> gas_stations[i];
    }

    int current_pos = 0, last_stop = 0;
    for (int i = 0; i <= n; ++i) {
        int next_station = (i < n ? gas_stations[i] : D);

        if (next_station - current_pos > m) {
            if (last_stop == current_pos) {
                cout << "Cant reach destination\n";
                return 0;
            }
            cout << "stop at gas station " << i << " (" << last_stop << " miles)\n";
            current_pos = last_stop;
        }

        if (i < n) {
            last_stop = gas_stations[i];
        }
    }

    return 0;
}
