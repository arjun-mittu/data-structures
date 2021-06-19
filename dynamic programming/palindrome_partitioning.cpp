// O(n^3)
int palindromicPartition(string s)
{
    int n = s.size();
    bool dp1[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            if (g == 0)
            {
                dp1[i][j] = true;
            }
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp1[i][j] = true;
                }
                else
                {
                    dp1[i][j] = false;
                }
            }
            else
            {
                if (s[i] == s[j] && dp1[i + 1][j - 1] == true)
                {
                    dp1[i][j] = true;
                }
                else
                {
                    dp1[i][j] = false;
                }
            }
        }
    }
    int dp2[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            if (g == 0)
            {
                dp2[i][j] = 0;
            }
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp2[i][j] = 0;
                }
                else
                {
                    dp2[i][j] = 1;
                }
            }
            else
            {
                if (dp1[i][j])
                {
                    dp2[i][j] = 0;
                }
                else
                {
                    int a = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        int left = dp2[i][k];
                        int right = dp2[k + 1][j];
                        a = min(a, left + right + 1);
                    }
                    dp2[i][j] = a;
                }
            }
        }
    }
    return dp2[0][n - 1];
}
// O(n^2)
int palindromicPartition(string s)
{
    int n = s.size();
    bool dp1[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            if (g == 0)
            {
                dp1[i][j] = true;
            }
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp1[i][j] = true;
                }
                else
                {
                    dp1[i][j] = false;
                }
            }
            else
            {
                if (s[i] == s[j] && dp1[i + 1][j - 1] == true)
                {
                    dp1[i][j] = true;
                }
                else
                {
                    dp1[i][j] = false;
                }
            }
        }
    }
    int dp[n];
    dp[0] = 0;
    for (int j = 1; j < n; j++)
    {
        if (dp1[0][j])
        {
            dp[j] = 0;
        }
        else
        {
            int a = INT_MAX;
            for (int i = j; i >= 1; i--)
            {
                if (dp1[i][j])
                {
                    a = min(a, dp[i - 1]);
                }
            }
            dp[j] = a + 1;
        }
    }

    return dp[n - 1];
}