class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = nums[0];
        int imax = nums[0];
        int imin = nums[0];
        for (int i = 1; i < n; i++)
        {
            int temp = imax;
            imax = max({nums[i], imax * nums[i], imin * nums[i]});
            imin = min({nums[i], imin * nums[i], temp * nums[i]});
            ans = max(ans, imax);
        }
        return ans;
    }
};