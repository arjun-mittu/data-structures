#include <iostream>
#include<algorithm>
#include <unordered_map>
using namespace std;
int longestSubbarraysum(int arr[], int n)
{
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == 0)
        {
            len = max(len, i + 1);
        }
        //used to check if already present in map
        if(m.find(pre)!=m.end()){
            len=max(len,i-m[pre]);
        }
        else{
            m[pre]=i;
        }
    }
    return len;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<longestSubbarraysum(arr,n);
}