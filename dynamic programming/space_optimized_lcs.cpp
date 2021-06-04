class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(2, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i % 2][j] = 1 + dp[(i + 1) % 2][j - 1];
                }
                else
                {
                    dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[n1 % 2][n2];
    }
};