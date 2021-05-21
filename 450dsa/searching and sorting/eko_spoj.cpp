#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool isvalid(int *arr,int n,int m,int ans){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>ans){
            sum+=arr[i]-ans;
        }
    }
    if(sum>=m) return true;
    return false;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    int max_element=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        max_element=max(max_element,arr[i]);
    }
    //sort(arr,arr+n);
    int s=0;
    //int e=arr[n-1];
    int e=max_element;
    int ans=INT_MIN;
    while(s<=e){
        int mid=(s+e)/2;
        if(isvalid(arr,n,m,mid)){
            //cout << arr[mid] << endl;
            ans=max(ans,mid);
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}