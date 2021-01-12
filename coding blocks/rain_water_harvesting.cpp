#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int water=0;
    int l_max=0;
    int r_max=0;
    int l=0;
    int r=n-1;
    while(l<=r){
        if(arr[l]<arr[r]){
            if(arr[l]>l_max){
                l_max=arr[l];
            }
            else{
                water+=l_max-arr[l];
            }
            l++;
        }
        else{
            if(arr[r]>r_max){
                r_max=arr[r];
            }
            else{
                water+=r_max-arr[r];
            }
            r--;
        }
    }
    cout<<water;
}