//
// #include <iostream>
//
// int main() {
//     int t;
//     std::cin >> t;
//
//     for (int i = 0; i < t; ++i) {
//         long long n;
//         std::cin >> n;
//
//         if (n <= 1) {
//             std::cout << "0" << std::endl;
//         } else {
//             long long result = (n - 2) / 2;
//             std::cout << result << std::endl;
//         }
//     }
//
//     return 0;
// }
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        long long n;
        cin >> n;                     // Number of candies
        cout << (n - 1) / 2 << endl;  // Compute number of valid distributions
    }
    return 0;
}
