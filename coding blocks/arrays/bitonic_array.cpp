#include<bits/stdc++.h>
using namespace std;
int length_left(int *arr, int n)
{
    int ans = 0;
    /*for (int i = 0; i <= n; i++)
    {
        if (arr[i] <= arr[i + 1] && arr[i] <= arr[n])
        {
            ans++;
        }
        else
        {
            ans = 0;
        }
    }*/
    for(int i=n;i>=0;i--){
        if(arr[i]<=arr[i+1] /*&& arr[i]<=arr[n+1]*/){
            ans++;
        }
        else{
            break;
        }
    }
    return ans;
}
int lenght_right(int *arr,int i,int n){
    int ans=0;
    for(int j=i;j<n;j++){
        if(arr[j-1]>=arr[j]){
            ans++;
        }
        else{
            break;
        }
    }
    return ans;
}
int solve(int *arr, int n)
{
    int max_ans=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int left = length_left(arr, i - 1);
        int right = lenght_right(arr, i + 1, n);
        max_ans=max(max_ans,left+right);
    }
    return max_ans+1;
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout<<solve(arr,n)<<endl;
    }
    return 0;
}