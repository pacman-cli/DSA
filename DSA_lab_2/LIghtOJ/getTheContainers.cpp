#include <iostream>

using namespace std;

#define SIZ 1005

bool isPossible(int);
int BS(long long, int);

int n, m, vessel[SIZ];

int main() {
    int tc, cn, res;
    long long low, total;
    cin >> tc;

    for (cn = 1; cn <= tc; cn++) {
        cin >> n >> m;
        total = low = 0;
        for (int i = 0; i < n; i++) {
            cin >> vessel[i];

            total += vessel[i];

            if (vessel[i] > low) low = vessel[i];
        }

        res = BS(total, low);
        cout << "Case " << cn << ": " << res << endl;
    }
}

bool isPossible(int capacity) {
    int temp;
    int cnt = 1;

    temp = 0;
    for (int i = 0; i < n; i++) {
        if (temp + vessel[i] <= capacity) {
            temp = temp + vessel[i];
        } else  // Filled to brim, new container needed
        {
            temp = vessel[i];
            cnt++;
        }
    }

    if (cnt > m)
        return false;

    else
        return true;
}

int BS(long long total, int maxCapacity) {
    int low, mid, ans;
    long long high;

    low = maxCapacity;
    high = total;

    while (low <= high) {
        mid = (low + high) / 2;

        if (isPossible(mid)) {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}
