#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
       
        int l=i+1;
        
        int r=n-1;
        while(l<r){
            int sum1=arr[i]+arr[l]+arr[r];
            if(sum1==target){
                cout<<arr[i]<<", "<<arr[l]<<" and "<<arr[r]<<endl;
                l++;r--;
            }
            else if(sum1>target){
                r--;
            }
            else if(sum1<target){
                l++;
            }
        }
    }
    return 0;
}