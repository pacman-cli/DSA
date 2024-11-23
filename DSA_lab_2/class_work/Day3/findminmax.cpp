#include<bits/stdc++.h>
using namespace std;
struct Res{
     int mx,mn;
};
Res findMaxMin(int A[], int i ,int j){
     if(i==j){
          return {A[i],A[i]};
     } else{
          int mid = (i+j)/2;
          Res res1 = findMaxMin(A,i,mid);
          Res res2 = findMaxMin(A,mid+1,j);

          int mx=max(res1.mx,res2.mx);
          int mn=min(res1.mn,res2.mn);
          return {mx,mn};
     }
}
int main(){
     int arr[]={1,2,3,4,5,6,7,8,9,10};
     int n=sizeof(arr)/sizeof(arr[0]);
     Res res = findMaxMin(arr,0,n-1);
     cout<<"Max:"<<res.mx<<" Min:"<<res.mn<<endl;
     return 0;
}