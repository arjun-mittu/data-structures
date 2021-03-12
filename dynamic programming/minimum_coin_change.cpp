#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int minCoins_top_down(int n, int coins[], int T, int dp[])
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    if (dp[n] != 0)
    {
        return dp[n];
    }
    for (int i = 0; i < T; i++)
    {
        if (n - coins[i] >= 0)
        {
            int subprob = minCoins_top_down(n - coins[i], coins, T, dp);
            ans = min(ans, subprob + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}
int minCoins_bottom_up(int N, int coins[], int T)
{
    int dp[100] = {0};
    // iterate over all states
    for (int n = 1; n <= N; n++)
    {
        dp[n] = INT_MAX;
        for (int i = 0; i < T; i++)
        {
            if (n - coins[i] >= 0)
            {
                int subprob = dp[n - coins[i]];
                dp[n]=min(dp[n],subprob+1);
            }
        }
    }
    return dp[N];
}
int main()
{
    int N = 15;
    int coins[] = {1, 7, 10};
    int dp[100] = {0};
    int T = sizeof(coins) / sizeof(int);
    //cout << minCoins_top_down(N, coins, T, dp) << endl;
    cout << minCoins_bottom_up(N, coins, T) << endl;
    return 0;
}