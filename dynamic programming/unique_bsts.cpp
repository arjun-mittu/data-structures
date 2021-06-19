#include <bits/stdc++.h>
using namespace std;
#define long long int;
int32_t main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = 0;
        int r = i - 1;
        dp[i] = 0;
        while (l <= i - 1)
        {
            dp[i] += dp[l] * dp[r];
            l++;
            r--;
        }
    }

    cout << dp[n];

    return 0;
}