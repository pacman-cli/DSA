#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cout << "n,k: " << endl;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "Sorted array in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    cout << "Sum" << sum << endl;

    return 0;
}
