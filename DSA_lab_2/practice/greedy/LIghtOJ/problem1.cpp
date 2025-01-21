#include <bits/stdc++.h>
using namespace std;

int main() {
    // Pre-calculating factorials from 0! to 19!
    long long int factorial[20] = {1};
    for (long long int i = 1; i <= 19; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    // Start of actual solution
    int testcase;
    cin >> testcase;
    for (int j = 1; j <= testcase; j++) {
        long long int n;
        cin >> n;

        vector<int> answer;
        for (int i = 19; i >= 0; i--) {  // Start from 19! down to 0!
            if (factorial[i] <= n) {
                n -= factorial[i];
                answer.push_back(i);
            }
        }

        // Output result
        cout << "Case " << j << ": ";
        if (n == 0) {
            if (answer.size() == 1 && answer[0] == 0) {
                // If the only factorial is 0!
                cout << "0!\n";
            } else {
                // Print the factorials in ascending order
                for (int i = answer.size() - 1; i > 0; i--) {
                    cout << answer[i] << "!+";
                }
                cout << answer[0] << "!\n";
            }
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}
