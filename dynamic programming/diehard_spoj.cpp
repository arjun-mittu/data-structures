#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[1001][1001];
int solve(int h,int a ,int i){
    if(h<=0 || a<=0) return 0;
    if(dp[h][a]!=-1) return dp[h][a];
    int x,y,z;
    x=y=z=0;
    if(i!=1) x=1+solve(h+3,a+2,1);
    if(i!=2) y=1+solve(h-5,a-10,2);
    if(i!=3) z=1+solve(h-20,a+5,3);
    return dp[h][a]=max({x,y,z});
}
int32_t main(){
    int T;
    cin>>T;
    while(T--){
        int H,A;
        cin>>H>>A;
        memset(dp,-1,sizeof(dp));
        cout<<max({solve(H+3,A+2,1),solve(H-5,A-10,2),solve(H-20,A+5,3)})<<endl;
        
    }
    return 0;
}