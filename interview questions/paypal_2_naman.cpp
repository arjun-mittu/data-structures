#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;
int solve(int n)
{
    int mod = 1000000007;
    if (n == 0)
        return 0;
    if (n == 1)
        return 3;
    if (n == 2)
        return 4;
    int dp_1[n + 1];
    int dp_0[n + 1];
    dp_1[1] = 3;
    dp_0[1] = 2;
    dp_1[2] = 4;
    dp_0[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        dp_1[i] = (dp_1[i - 1] + ((3 * dp_0[i - 2]) % mod)) % mod;
        dp_0[i] = (((2 * dp_0[i - 1]) % mod) + ((2 * dp_1[i - 2]) % mod) % mod);
    }
    return dp_1[n];
}
int32_t main()
{
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}