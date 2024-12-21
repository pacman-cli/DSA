// C++ program to find the longest common prefix
// using Divide and Conquer Algorithm

#include <iostream>
#include <vector>
using namespace std;

// A Utility Function to find the common prefix between
// strings s1 and s2
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

// A Divide and Conquer based function to find the
// longest common prefix. This is similar to the
// merge sort technique
string commonPrefix(vector<string> &arr, int l, int r) {

    // Base Case: common prefix for a single string is
    // the string itself
    if (l == r)
        return arr[l];

    if (l < r) {
        int mid = l + (r - l) / 2;

        // Find Longest Common Prefix of first part
        string p1 = commonPrefix(arr, l, mid);

        // Find Longest Common Prefix of second part
        string p2 = commonPrefix(arr, mid + 1, r);

        // Find and return the Longest Common Prefix
        // of subarray arr[l ... r]
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