#include<bits/stdc++.h>
using namespace std;
void LCS(string s1, string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+2,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<char> ans;
    int i=n1,j=n2;
    while(i!=0 && j!=0){
        if(dp[i][j]==dp[i][j-1]){
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            ans.push_back(s1[i-1]);
            i--;j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (char x : ans)
    {
        cout << x;
    }
    //return dp[n1][n2];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    LCS(s1,s2);
    return 0;
}