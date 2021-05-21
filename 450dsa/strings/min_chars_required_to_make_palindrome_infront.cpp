#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> longestPrefix(string s)
    {
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
        return dp;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution st;
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());
    string use = s + "$" + rev;
    int m = use.size();
    vector<int> dp = st.longestPrefix(use);
    //cout<<n<<"-"<<dp[m-1];
    cout << n - dp[m - 1];
    return 0;
}

//TLE
int n = s.size();
int i = 1;
int start, end;
int largest_palindrome = 1;
for (i = 1; i < n; i++)
{
    start = 0;
    end = i;
    bool flag = true;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            flag = false;
            break;
        }
        start++;
        end--;
    }
    if (flag)
    {
        largest_palindrome = i + 1;
    }
}
return n - largest_palindrome;