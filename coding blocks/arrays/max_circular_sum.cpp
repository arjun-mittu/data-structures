#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            arr[i] = -1 * arr[i];
        }

        int current = 0, best = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (current >= 0)
            {
                current += arr[i];
            }
            else
            {
                current = arr[i];
            }
            best = max(best, current);
        }
        if (sum == -1 * best)
        {
            best = 0;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = -1 * arr[i];
        }
        current = 0;
        int best1 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (current >= 0)
            {
                current += arr[i];
            }
            else
            {
                current = arr[i];
            }
            best1 = max(best1, current);
        }
        return max(sum + best, best1);
    }
};
bool check_negative(int arr[], int n)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            return true;
            break;
        }
    }
    return false;
}
int maxSubarraySum(int arr[], int n)
{
    if (check_negative(arr, n))
    {
        int currsum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            currsum += arr[i];
            if (currsum < 0)
            {
                currsum = 0;
            }
            ans = max(ans, currsum);
        }
        return ans;
    }
    else
    {
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i]);
        }
        return ans;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int cumsum=0;
        int inver_arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cumsum+=arr[i];
            inver_arr[i]=-arr[i];
        }
        //cout << maxSubarraySum(arr, n) << endl;
        //cout<<cumsum;
        int k_ans = maxSubarraySum(inver_arr,n);
        int ans=cumsum + k_ans;
        if(k_ans == 0){
            ans = cumsum;
        }
        int k = maxSubarraySum(arr, n);
        //cout<<k<<" "<<ans<<endl;
        cout<<max(k, ans)<<endl;
        Solution s;
        cout<<s.circularSubarraySum(arr,n)<<endl;

    }

    return 0;
}