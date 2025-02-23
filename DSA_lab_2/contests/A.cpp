// #include <iostream>
// #include <string>
//
// using namespace std;
//
// int countOccurrences(const string &s, const string &pattern) {
//     int count = 0;
//     size_t pos = s.find(pattern);  // Find first occurrence
//     while (pos != string::npos) {
//         count++;
//         pos = s.find(pattern, pos + 1);  // Search for next occurrence
//     }
//     return count;
// }
//
// int main() {
//     string s;
//     cin >> s;
//     cout << countOccurrences(s, "hznu") << endl;
//     return 0;
// }
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int count = 0;
    for (size_t i = 0; i <= str.size() - 4; ++i) {
        if (str.substr(i, 4) == "hznu") {
            ++count;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
