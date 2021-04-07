#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
bool isPossible(int *arr,int n,int m,int curr_min){
    int studentused=1;
    int pages_reading=0;
    for(int i=0;i<n;i++){
        if(pages_reading+arr[i]>curr_min){
            studentused++;
            pages_reading=arr[i];//next student pages
            if(studentused>m){
                return false;
            }
        }
        else{
            pages_reading+=arr[i];
        }
    }
    return true;
}
int findPages(int *arr,int n,int m){
    int sum=0;
    //if n<m
    if(n<m){
        return -1;
    }
    //count number of pages
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int s=arr[n-1];
    int e=sum;
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(arr,n,m,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            //it is not possible to divide at x pages
            // increase the no of pages
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<findPages(arr,n,m)<<endl;
    }
    return 0;
}