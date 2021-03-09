#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
//n->n/3, n->n/2,n->n-1

int minstep_top_down(int n, int dp[])
{
    //base
    if (n == 1)
    {
        return 0;
    }
    //rec case
    //look up if n already computed
    if (dp[n] != 0)
    {
        return dp[n];
    }
    //compute if dp[n] is not known
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 3 == 0)
    {
        op1 = minstep_top_down(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minstep_top_down(n / 2, dp) + 1;
    }
    op3 = minstep_top_down(n - 1, dp) + 1;
    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}
int minstep_bottom_up(int n)
{
    int dp[100] = {0};
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if (i % 3 == 0) //i ki jagah n bhi likh skte hai
        {
            op1 = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];
        dp[i] = min(min(op1, op2), op3) + 1;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    //cout<<minstep_top_down(n,dp);
    cout << minstep_bottom_up(n);
    return 0;
}