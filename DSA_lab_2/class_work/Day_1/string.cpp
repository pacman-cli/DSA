// This program demonstrates various string operations in C++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Method 1: Direct string initialization
    string str1 = "Hello World";
    cout << "String 1: " << str1 << endl;

    // Method 2: Converting char array to string
    char chr_str[] = "Hello Universe";
    string str2 = string(chr_str);
    cout << "String 2: " << str2 << endl;

    // String length
    cout << "Length of str1: " << str1.length() << endl;

    // Accessing individual characters
    cout << "str1[0]: " << str1[0] << " str1[6]: " << str1[6] << endl;

    // String concatenation using +=
    str1 += ".";
    cout << "str1 after adding '.': " << str1 << endl;

    // Multiple concatenations
    str2 += ".";
    str2 += str1;
    cout << "str2 after concatenation: " << str2 << endl;

    // String input demonstration
    string word, line;
    cout << "Enter a word: ";
    cin >> word;              // Reads until whitespace
    cin.sync();              // Clear buffer
    cout << "You entered: " << word << endl;

    cout << "Enter a line: ";
    getline(cin, line);      // Reads entire line
    cout << "You entered: " << line << endl;

    return 0;
}

/* Additional string manipulation examples:

// Example 1: String operations
void stringOperations() {
    string str = "Hello World";
    
    // Substring
    string sub = str.substr(0, 5);  // "Hello"
    
    // Find
    size_t pos = str.find("World");  // Returns 6
    
    // Replace
    str.replace(6, 5, "C++");  // "Hello C++"
    
    // Insert
    str.insert(5, " there");  // "Hello there World"
    
    // Erase
    str.erase(5, 6);  // Removes " there"
}

// Example 2: String comparison
void stringComparison() {
    string s1 = "apple";
    string s2 = "banana";
    
    bool less = s1 < s2;           // true
    bool equal = s1 == s2;         // false
    bool greater = s1 > s2;        // false
    
    // Compare specific portion
    int result = s1.compare(0, 2, s2, 0, 2);
}

// Example 3: String transformation
void stringTransform() {
    string str = "Hello World";
    
    // To uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    // To lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    // Reverse string
    reverse(str.begin(), str.end());
}

// Example 4: String parsing
void stringParsing() {
    string str = "123,456,789";
    stringstream ss(str);
    string token;
    
    while (getline(ss, token, ',')) {
        cout << token << endl;
    }
}

// Example 5: String conversion
void stringConversion() {
    // String to number
    string numStr = "123";
    int num = stoi(numStr);
    double dbl = stod("123.456");
    
    // Number to string
    string str1 = to_string(123);
    string str2 = to_string(123.456);
}

// Example 6: String view (C++17)
void stringViewExample() {
    string_view sv = "Hello World";
    cout << sv.substr(0, 5) << endl;
}

// Example 7: Raw string literals
void rawStrings() {
    string normal = "First line\nSecond line";
    string raw = R"(First line
Second line)";
}

Usage examples:
stringOperations();    // Basic string operations
stringComparison();    // Compare strings
stringTransform();     // Transform strings
stringParsing();       // Parse strings
stringConversion();    // Convert strings
stringViewExample();   // Use string_view
rawStrings();          // Raw string literals
*/