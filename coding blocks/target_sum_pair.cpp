#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int l=0;
    int r=n-1;
    sort(arr,arr+n);
    while(l<r){
        int sum=arr[l]+arr[r];
        if(sum==target){
            cout<<arr[l]<<" and "<<arr[r]<<endl;
            l++;r--;
        }
        else if(sum>target){
            r--;
        }
        else if(sum<target){
            l++;
        }
    }
    return 0;
}