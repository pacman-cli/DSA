#include <iostream>
using namespace std;
int main()
{
    string old_s = "Thank you very very much";
    cout << old_s << endl;
    int found = old_s.find("very");
    string new_s = old_s.substr(0, found);
    cout << new_s << endl;
    new_s += old_s.substr(found + 5);
    cout << new_s << endl;
    return 0;
}