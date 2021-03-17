#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    vector<vector<int>> dp(n+1,vector<int>(s+1,0));
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for(int i=0;i<=n;i++){
        for(int w=0;w<=s;w++){
            if(i==0 || w==0){
                dp[i][w]==0;
            }
            else if(wt[i-1]<=w){
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    cout<<dp[n][s];
    return 0;
}