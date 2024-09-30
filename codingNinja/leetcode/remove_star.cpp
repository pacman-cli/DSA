#include <bits/stdc++.h>
#include <stack>
using namespace std;

string removeStars(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '*')
        {
            // pop the closest character if a star is encountered
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(c);
        }
    }
    string result = "";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    // since we added characters from top to bottom, reverse the result
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    // test case 1
    string s1 = "leet**cod*e";
    cout << "Input:" << s1 << endl;
    cout << "Output:" << removeStars(s1) << endl;

    // test case 1
    string s2 = "erase*****";
    cout << "Input:" << s2 << endl;
    cout << "Output:" << removeStars(s2) << endl;

    // test case 1
    string s3 = "abc*def**ghi***";
    cout << "Input:" << s3 << endl;
    cout << "Output:" << removeStars(s3) << endl;
}