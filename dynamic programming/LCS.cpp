#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <cstring>
using namespace std;
int LCS(string s1, string s2, int i, int j)
{
    if (i == s1.length() || j == s2.length())
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + LCS(s1, s2, i + 1, j + 1);
    }
    int op1 = LCS(s1, s2, i + 1, j);
    int op2 = LCS(s1, s2, i, j + 1);
    return max(op1, op2);
}
int LCS_top_down(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
    {
        return 0;
    }
    //check if a state is already computed
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])//check ifs1[i]==s2[i]
    {
        return dp[i][j] = 1 + LCS_top_down(s1, s2, i + 1, j + 1, dp);
    }
    int op1 = LCS_top_down(s1, s2, i + 1, j, dp);
    int op2 = LCS_top_down(s1, s2, i, j + 1, dp);
    return dp[i][j] = max(op1, op2);
}
int lcs_bottom_up(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                int op1=dp[i-1][j];
                int op2=dp[i][j-1];
                dp[i][j]=max(op1,op2);
            }
        }
    }
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<char> result;
    int i=n1,j=n2;
    while(i!=0 && j!=0){
        if(dp[i][j]==dp[i][j-1]){
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            result.push_back(s1[i-1]);
            i--;j--;
        }
    }
    reverse(result.begin(),result.end());
    for(char x:result){
        cout<<x;
    }
    cout<<endl;
    return dp[n1][n2];
}
int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1)); //n1 X n2
    cout << LCS(s1, s2, 0, 0) << endl;
    cout << LCS_top_down(s1, s2, 0, 0, dp) << endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<lcs_bottom_up(s1,s2);
    return 0;
}