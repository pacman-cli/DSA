#include <bits/stdc++.h>

#include <vector>
using namespace std;
long long merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    long long inv_count = 0;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + 1];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && i < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[i];
            j++;
            inv_count += n1 - i;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n1) {
        arr[k] = leftArray[j];
        j++;
        k++;
    }
    return inv_count;
}
long long mergeSort(vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
}
