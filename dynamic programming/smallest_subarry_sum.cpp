#include <bits/stdc++.h>

using namespace std;

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
    int ans=INT_MAX;
    int temp=INT_MAX;
    for(int i=0;i<n;i++){
        if(temp>0){
            temp=arr[i];
        }
        else{
            temp+=arr[i];
        }
        ans=min(ans,temp);
    }
    return ans;
}

// Driver program to test above
int main()
{
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "
         << smallestSumSubarr(arr, n);
    return 0;
}