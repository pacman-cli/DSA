// This program demonstrates string copying and comparison in C++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Original string
    string str1 = "Hello";
    
    // Create a copy of str1
    string str2 = str1;  // Deep copy, str2 gets its own memory
    
    // Modify str1 - str2 remains unchanged
    str1[0] = 'y';  // Changes str1 to "yello"
    cout << "str1: " << str1 << ", str2: " << str2 << endl;
    
    // Compare strings
    // Compare with literal
    if (str2 == "Hello")
    {
        cout << "str2 is still 'Hello'" << endl;
    }
    
    return 0;
}

/* Additional string copy and comparison examples:

// Example 1: Different ways to copy strings
void stringCopyExamples() {
    string original = "Hello";
    
    // Method 1: Assignment operator
    string copy1 = original;
    
    // Method 2: Copy constructor
    string copy2(original);
    
    // Method 3: Substring copy
    string copy3 = original.substr();
    
    // Method 4: Character by character
    string copy4;
    copy4.assign(original.begin(), original.end());
}

// Example 2: String references
void stringReferences() {
    string str = "Hello";
    
    // Reference - changes affect original
    string& ref = str;
    ref[0] = 'Y';  // Changes str to "Yello"
    
    // Const reference - cannot modify
    const string& constRef = str;
    // constRef[0] = 'H';  // Error!
}

// Example 3: String comparison methods
void stringComparisonMethods() {
    string s1 = "apple";
    string s2 = "banana";
    
    // Method 1: Comparison operators
    bool isLess = s1 < s2;
    bool isEqual = s1 == s2;
    bool isGreater = s1 > s2;
    
    // Method 2: compare() function
    int result = s1.compare(s2);  // negative if s1 < s2
    
    // Method 3: Compare substrings
    bool subEqual = s1.compare(0, 2, s2, 0, 2) == 0;
}

// Example 4: Case-insensitive comparison
bool caseInsensitiveEqual(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    for (size_t i = 0; i < s1.length(); ++i) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return false;
        }
    }
    return true;
}

// Example 5: String memory management
void stringMemory() {
    string str = "Hello";
    cout << "Capacity: " << str.capacity() << endl;
    cout << "Size: " << str.size() << endl;
    
    // Reserve space
    str.reserve(100);
    
    // Shrink to fit
    str.shrink_to_fit();
}

// Example 6: Moving strings (C++11)
void stringMove() {
    string source = "Hello World";
    string dest = move(source);  // source is now empty
    
    // After move, source is in valid but unspecified state
    cout << "source: " << source << endl;      // Might be empty
    cout << "dest: " << dest << endl;          // Contains "Hello World"
}

Usage examples:
stringCopyExamples();       // Different copy methods
stringReferences();         // Reference behavior
stringComparisonMethods();  // Compare strings
caseInsensitiveEqual("Hello", "HELLO");  // Case insensitive comparison
stringMemory();            // Memory management
stringMove();              // Move semantics
*/