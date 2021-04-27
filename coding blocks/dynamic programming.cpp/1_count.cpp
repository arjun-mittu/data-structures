#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int first=0;
    int zero_count=0,l=0,r=0,max_length=0;
    for(int r=0;r<n;r++){
        if(arr[r]==0) zero_count++;
        while(zero_count>k){
            if(arr[l]==0) zero_count--;
            l++;
        }
        //max_length=max(max_length,r-l+1);
        int curr_ans=r-l+1;
        if(max_length<curr_ans){
            max_length=curr_ans;
            first=l;
        }
    }
    cout<<max_length<<endl;
    for(int i=first;i<first+max_length;i++) arr[i]=1;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}