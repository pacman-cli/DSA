#include<iostream>
#include<vector>
using namespace std;
int knapSack(int val[],int wt[],int n, int W){
  int table[100][100];
  for(int w=0;w<W;w++){
    table[0][w]=0;
  }
  for(int i=0;i<n;i++){
    table[i][0]=0;
    for(int w=0;w<W;w++){
      if(wt[i]<=w){
        table[i][w]= max(table[i-1][w-wt[i]]+val[i],table[i-1][w]);
      }else{
        table[i][w]= table[i-1][w];
      }
    }
  }
  int i=n;
  int w=W;
  vector<int> taken_items;
  while(i>=0&&w>=0){
      if(table[i][w]==val[i]+table[i-1][w-wt[i]]){
        taken_items.push_back(i);
        w-=wt[i];
        i--;
      }else{
        i--;
      }
  }
}
int main(){
  int profit[]={0,10,15,40};//0 is the dummy value
  int weight[]={0,1,2,3};// 0 is the dummy value
  int W=6;
  int n=3; //number of items
  cout<<knapSack(profit,weight,n,W);
}
