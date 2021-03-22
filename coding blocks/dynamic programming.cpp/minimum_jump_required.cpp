#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n)
{
    int dp[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
    dp[0] = 0;
    for (i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return dp[n - 1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<minJumps(arr,n)<<endl;
    }

    return 0;
}