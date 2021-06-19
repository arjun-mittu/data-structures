class Solution
{
public:
    int maxProfit(int K, vector<int> &A)
    {
        int N = A.size();
        if (N == 0 || K == 0)
            return 0;
        int dp[K + 1][N];
        for (int i = 0; i < N; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= K; i++)
        {
            dp[i][0] = 0;
        }
        for (int t = 1; t <= K; t++)
        {
            for (int d = 1; d < N; d++)
            {
                dp[t][d] = dp[t][d - 1];
                for (int pd = 0; pd < d; pd++)
                {
                    int ptilltm1 = dp[t - 1][pd];
                    int ptth = A[d] - A[pd];
                    dp[t][d] = max(dp[t][d], ptth + ptilltm1);
                }
            }
        }
        return dp[K][N - 1];
    }
};

class Solution
{
public:
    int maxProfit(int K, vector<int> &A)
    {
        int N = A.size();
        if (N == 0 || K == 0)
            return 0;
        int dp[K + 1][N];
        for (int i = 0; i < N; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= K; i++)
        {
            dp[i][0] = 0;
        }
        for (int t = 1; t <= K; t++)
        {
            int temp = INT_MIN;
            for (int d = 1; d < N; d++)
            {
                temp = max(temp, dp[t - 1][d - 1] - A[d - 1]);
                dp[t][d] = max(temp + A[d], dp[t][d - 1]);
            }
        }
        return dp[K][N - 1];
    }
};