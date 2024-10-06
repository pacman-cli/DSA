#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<string> split(const string &sentence)
{
    vector<string> v;
    string word;
    isstringstream stream(sentence);
    while (stream >> word)
    {
        v.push_back(word);
    }
    return v;
}
// to check similar or not
bool areSentencesSimilar(string sentence1, string sentence2)
{
    vector<string> v1 = split(sentence1);
    vector<string> v2 = split(sentence2);
    int i = 0; // for left side
    int j = 0; // for right side index
    // compareing from left side index
    while (i < v1.size() && i < v2.size() && v1[i] == v2[i])
    {
        i++;
    }

    // compareing from right side
    while (j < v1.size() - i && j < v2.size() - i && v1[v1.size() - 1 - j] == v2[v2.size() - 1 - j])
    {
        j++;
    }
    // checking middle parts
    return i + j >= min(v1.size(), v2.size());
}
int main()
{
    string s1 = "My name is Haley";
    string s2 = "My Haley";
    cout << (areSentencesSimilar(s1, s2) ? "true" : "false") << endl;
    return 0;
}