#include<iostream>
using namespace std;
int sumofDigits(int n){
    if(n<10)
    return n;

    return (n%10) + sumofDigits(n/10);

}

int main(){
    int n;
    cin>>n;
    cout<<"Sum:"<<sumofDigits(n);
}