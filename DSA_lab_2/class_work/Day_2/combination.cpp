#include<iostream>
using namespace std;
int nCr(int n,int r){
    if(n<r){
        return 0;
    }
    if(r==0) return 0;
    if(r==1) return n;
    if(n==1) return 1;

    return nCr(n-1,r)+nCr(n-1,r-1);
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<"Combination:"<<(n,r);
}