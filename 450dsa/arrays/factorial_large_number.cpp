class Solution
{
public:
    int mul(int x, vector<int> &ans, int ans_size)
    {
        int carry = 0;
        for (int i = 0; i < ans_size; i++)
        {
            int prod = ans[i] * x + carry;
            ans[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
            ans_size++;
        }
        return ans_size;
    }
    vector<int> factorial(int N)
    {
        // code here
        vector<int> ans;
        ans.push_back(1);
        int ans_size = 1;
        for (int x = 2; x <= N; x++)
        {
            ans_size = mul(x, ans, ans_size);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};