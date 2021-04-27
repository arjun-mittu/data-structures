#include <bits/stdc++.h>
using namespace std;
int count(int n, int W, int price[])
{
    vector<int> val;
    vector<int> wt;
    // int size =0;
    for (int i = 0; i < W; i++)
    {
        if (price[i] != -1)
        {
            val.push_back(price[i]);
            //   wt.push_back(i);
            wt.push_back(i + 1);
            //   size++;
        }
    }
    // n = size;
    //Study vectors:
    n = val.size();
    int dp[n + 1][W + 1];
    // for(int i=0;i<n;i++) dp[i][0]  = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    // for(int j=0;j<W;j++)  dp[0][j] = INT_MAX;
    for (int j = 0; j <= W; j++)
        dp[0][j] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            // if(wt[i] > j)
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                //   dp[i][j] = min(dp[i-1][j] , dp[i-1][j - wt[i-1]] + val[i-1] );
                dp[i][j] = min(dp[i - 1][j], dp[i][j - wt[i - 1]] + val[i - 1]);
        }
    }
    if (dp[n][W] == INT_MAX)
        return -1;
    else
        return dp[n][W];
}
int main()
{
    int n, W;
    cin >> n >> W;
    int price[W];
    for (int i = 0; i < W; i++)
        cin >> price[i];
    cout << count(W, W, price);

    return 0;
}