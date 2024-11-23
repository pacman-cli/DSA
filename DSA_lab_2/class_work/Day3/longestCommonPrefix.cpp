#include <iostream>
#include <vector>
using namespace std;
string commonPrefixUtil(string &s1, string &s2) {
    string res;
    int n1 = s1.length(), n2 = s2.length();

    for (int i = 0; i < n1 && i < n2; i++) {
        if (s1[i] != s2[i])
            break;
        res.push_back(s1[i]);
    }

    return res;
}

string commonPrefix(vector<string> &arr, int l, int r) {
    if (l == r)
        return arr[l];

    if (l < r) {
        int mid = l + (r - l) / 2;

        string p1 = commonPrefix(arr, l, mid);

        string p2 = commonPrefix(arr, mid + 1, r);

        return commonPrefixUtil(p1, p2);
    }
    return "";
}

string longestCommonPrefix(vector<string> &arr) {
    return commonPrefix(arr, 0, arr.size() - 1);
}

int main() {
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    cout << longestCommonPrefix(arr);
    return 0;
}