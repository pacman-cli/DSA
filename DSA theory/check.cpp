#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 55, 56, 60, 70, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int median = size/2;
    
    cout <<"index:" << median << "\nmedian:" << arr[median]<< endl;
    return 0;
}