#include<bits/stdc++.h>
using namespace std;
long long int dp[100][100];
int optimal_solve(long long int a[],int i,int j){
    if(i>j){
        return 0;
    }
    if(j==i+1){
        return dp[i][j]=max(a[i],a[j]);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int op1=a[i]+min(optimal_solve(a,i+2,j),optimal_solve(a,i+1,j-1));
    int op2=a[j]+min(optimal_solve(a,i,j-2),optimal_solve(a,i+1,j-1));
    return dp[i][j]=max(op1,op2);
}
int main(){
    int n;cin>>n;
    memset(dp,-1,sizeof dp);
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<optimal_solve(a,0,n-1);
    return 0;
}