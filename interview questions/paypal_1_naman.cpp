#include <bits/stdc++.h>
#define int long long int
using namespace std;
char grid[501][501];
int dp[501][501];
bool vis[501][501];
int solve(int i, int j, int n, int m, char blockage)
{
    if (i == n - 1 && j == m - 1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    vis[i][j] = true;
    int ans1, ans2, ans3, ans4;
    ans1 = ans2 = ans3 = ans4 = 1e9;
    if (i > 0 && grid[i - 1][j] != blockage)
    {
        if (!vis[i - 1][j])
        {
            ans1 = 1 + solve(i - 1, j, n, m, blockage);
        }
    }
    if (j > 0 && grid[i][j - 1] != blockage)
    {
        if (!vis[i][j - 1])
        {
            ans2 = 1 + solve(i, j - 1, n, m, blockage);
        }
    }
    if (i < n - 1 && grid[i + 1][j] != blockage)
    {
        if (!vis[i + 1][j])
        {
            ans3 = 1 + solve(i + 1, j, n, m, blockage);
        }
    }
    if (j < m - 1 && grid[i][j + 1] != blockage)
    {
        if (!vis[i][j + 1])
        {
            ans4 = 1 + solve(i, j + 1, n, m, blockage);
        }
    }
    dp[i][j] = min({ans1, ans2, ans3, ans4});
    return dp[i][j];
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    grid[n][m];
    dp[n][m];
    vis[n][m];
    memset(dp, -1, sizeof dp);
    memset(vis, false, sizeof vis);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int first = solve(0, 0, n, m, '*');
    if (first >= 1e9)
        cout << -1 << endl;
    else
        cout << first << endl;
    memset(dp, -1, sizeof dp);
    memset(vis, false, sizeof vis);
    first = solve(0, 0, n, m, '#');

    if (first >= 1e9)
        cout << -1 << endl;
    else
        cout << first << endl;
    return 0;
}