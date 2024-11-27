// This program demonstrates different ways to handle input/output in C++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Method 1: Basic string input (stops at whitespace)
    char str[100];
    cout << "Enter a string (stops at space): ";
    cin >> str;
    cout << "You entered: " << str << endl;

    // Clear input buffer to handle next input properly
    cin.sync();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Method 2: Get entire line including spaces
    cout << "Enter a line of text: ";
    cin.get(str, 100);
    cout << "You entered: " << str << endl;

    return 0;
}

/* Additional input/output examples:

// Example 1: Using getline with string
void stringExample() {
    string line;
    cout << "Enter a line: ";
    getline(cin, line);
    cout << "You entered: " << line << endl;
}

// Example 2: Reading multiple values
void multipleInputs() {
    int num;
    char ch;
    string word;
    
    cout << "Enter number, character, and word: ";
    cin >> num >> ch >> word;
    cout << "Number: " << num << endl
         << "Character: " << ch << endl
         << "Word: " << word << endl;
}

// Example 3: Formatted output
void formattedOutput() {
    double pi = 3.14159265359;
    cout << fixed << setprecision(2) << pi << endl;  // Shows 3.14
    cout << scientific << pi << endl;                // Scientific notation
    cout << setw(10) << setfill('*') << 42 << endl; // Padding with *
}

// Example 4: Reading until EOF
void readUntilEOF() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        cout << "Read: " << line << endl;
    }
}

// Example 5: Reading specific number of characters
void readNChars() {
    char buffer[10];
    cout << "Enter up to 9 characters: ";
    cin.read(buffer, 9);
    buffer[9] = '\0';
    cout << "Read: " << buffer << endl;
}

Usage examples:
stringExample();      // Read entire line using string
multipleInputs();     // Read multiple values
formattedOutput();    // Show formatted output
readUntilEOF();       // Read until empty line
readNChars();         // Read specific number of chars
*/