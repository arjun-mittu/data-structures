#include <bits/stdc++.h>
using namespace std;
long long int dp[1000000];
long long int solve(long long int n)
{
    if (n <= 100000 && dp[n] != -1)
    {
        return dp[n];
    }
    if (n <= 11)
    {
        return dp[n] = n;
    }
    long long int ans = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
    if (n <= 1000000)
        return dp[n] = ans;
    return ans;
}

int main()
{
    long long int n, i;
    cin >> n;
    for (i = 0; i <= 1000000; i++)
    {
        dp[i] = -1;
    }
    cout << solve(n);
}