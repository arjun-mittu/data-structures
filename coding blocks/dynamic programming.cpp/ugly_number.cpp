#include <bits/stdc++.h>
using namespace std;
#define int long long int
int solve(int n)
{
    int dp[10000];
    dp[0] = 1;
    if (n - 1 == 0)
    {
        return 1;
    }
    int i2 = 0, i3 = 0, i5 = 0;
    int next_2 = 2, next_3 = 3, next_5 = 5;
    int next = 1;
    for (int i = 1; i < n; i++)
    {
        next = min(next_2, min(next_3, next_5));
        dp[i] = next;
        if (next == next_2)
        {
            i2++;
            next_2 = dp[i2] * 2;
        }
        if (next == next_3)
        {
            i3++;
            next_3 = dp[i3] * 3;
        }
        if (next == next_5)
        {
            i5++;
            next_5 = dp[i5] * 5;
        }
    }
    return next;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}