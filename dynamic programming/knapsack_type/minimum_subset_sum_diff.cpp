#include <bits/stdc++.h>
#define long long int
using namespace std;
int solve(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - nums[i - 1] >= 0)
            {
                dp[i][j] |= dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    int diff = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            diff = sum - 2 * i;break;
        }
    }

    return diff;
}
int32_t main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << solve(nums) << endl;
    }
    return 0;
}