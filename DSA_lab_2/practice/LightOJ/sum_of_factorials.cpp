#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to find factorial representation using greedy approach
bool findFactorialSum(long long n, vector<int>& result) {
    result.clear();
    
    // Calculate factorials up to 20 (as 20! > 10^18)
    vector<long long> facts;
    facts.push_back(1);  // 0!
    for (int i = 1; i <= 20; i++) {
        facts.push_back(factorial(i));
    }
    
    // Try to build up from smallest factorial
    for (int i = 20; i >= 0; i--) {
        if (n >= facts[i]) {
            result.push_back(i);
            n -= facts[i];
        }
    }
    
    return n == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        long long n;
        cin >> n;
        
        vector<int> result;
        bool possible = findFactorialSum(n, result);
        
        cout << "Case " << caseNum << ": ";
        if (!possible) {
            cout << "impossible\n";
        } else {
            sort(result.begin(), result.end());  // Sort in ascending order
            cout << result[0] << "!";
            for (int i = 1; i < result.size(); i++) {
                cout << "+" << result[i] << "!";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
