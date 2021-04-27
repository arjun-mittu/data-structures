#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll sum;
//It doesn't require that much space
ll n, a[5001];

int main()
{
    ll i, j;

    cin >> n >> sum;
    bool dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (i = 0; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= sum; j++)
        {
            if (a[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
        }
    }

    if (dp[n][sum])
        cout << "Yes";
    else
        cout << "No";
}
