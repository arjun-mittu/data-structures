#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    vector<int> dp(s+1,0);
    for(int i=0;i<=s;i++){
        for(int j=0;j<n;j++){
            if(wt[j]<=i){
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    }
    cout<<dp[s];

    return 0;
}