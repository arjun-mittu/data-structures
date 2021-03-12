#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int maxsum(int a[], int n)
{
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int max_so_far = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_so_far = max(dp[i], max_so_far);
    }
    return max_so_far;
}
int maxsum_space_opt(int a[], int n)
{
    int curr_sum = 0;
    int max_so_far = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += a[i];
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        max_so_far = max(curr_sum, max_so_far);
    }
    return max_so_far;
}
//if array contains all negative value then return smallest negative element
int main()
{
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << maxsum(arr, n) << endl;
    cout << maxsum_space_opt(arr, n) << endl;
    return 0;
}