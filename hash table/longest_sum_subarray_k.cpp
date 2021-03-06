#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int longestSubbarrayksum(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == k)
        {
            len = max(len, i + 1);
        }
        //used to check if already present in map
        if (m.find(pre-k) != m.end())
        {
            len = max(len, i - m[pre-k]);
        }
        else
        {
            m[pre] = i;
        }
    }
    return len;
}
int main()
{
    int n,k;
    cin >> n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longestSubbarrayksum(arr, n,k);
}