int n = s.size();
vector<int> dp(n + 1, 0);
int j = 0;
int i = 1;
dp[0] = j;
while (i < n)
{
    if (s[i] == s[j])
    {
        j++;
        dp[i] = j;
        i++;
    }
    else if (j > 0)
    {
        j = dp[j - 1];
    }
    else
    {
        i++;
    }
}