#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /* LIS method 1
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i]=1;//every element can end at lenght 1
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int lis=0;
    for (int i = 0; i < n; i++)
    {
        lis=max(lis,dp[i]);
    }
    cout<<lis;*/

    //method 2
    /*
    int dp[n + 1]; //lengths from 0-n
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        //understading loop
        for (int length = 0; length <= n; length++)
        {
            cout << dp[length] << " ";
        }
        cout << endl;
        for (int length = 0; length < n; length++)
        {
            if (dp[length] < a[i] && a[i] < dp[length + 1])
            {
                dp[length + 1] = a[i];
            }
        }
        for (int length = 0; length <= n; length++)
        {
            cout << dp[length] << " ";
        }
        cout << endl;
    }
    int lis = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] != INT_MAX)
            lis = i;
    }
    cout << lis;*/
    

    //method 3
    int dp[n + 1]; //lengths from 0-n
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;
    for(int i=0;i<n;i++){
        int length=upper_bound(dp,dp+n+1,a[i])-dp;
        if(dp[length-1]<a[i] && a[i]<dp[length]){
            dp[length]=a[i];
        }
    }
    int lis = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] != INT_MAX)
            lis = i;
    }
    cout << lis;
    return 0;
}