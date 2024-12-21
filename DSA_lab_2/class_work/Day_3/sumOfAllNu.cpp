#include<bits/stdc++.h>
using namespace std;
int sumOdd(int arr[],int i, int j){
     if(i==j){
          //if(arr[i]%2 != 0)
          return arr[i];
          //else return 0;
     }
     int mid =(i+j)/2;

     int c1=sumOdd(arr,i,mid);
     int c2=sumOdd(arr,mid+1,j);
  return c1+c2;
}
int main(){
     int arr[]={1,2,3,4,5,6,7,8,9,10};
     int n=sizeof(arr)/sizeof(arr[0]);
     cout<<"Sum of odd numbers in the array: "<<sumOdd(arr,0,n-1)<<endl;
     return 0;
}