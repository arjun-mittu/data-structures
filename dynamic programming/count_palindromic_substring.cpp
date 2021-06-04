class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        bool dp[n][n];
        int ans = 0;
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = true;
                    ans++;
                }
                else if (g == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return ans;
    }
};