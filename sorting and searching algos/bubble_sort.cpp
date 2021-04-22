#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int k=1;k<=n-1;k++){
        int ptr=0;
        while(ptr<=n-k){
            if(arr[ptr]>arr[ptr+1]){
                swap(arr[ptr],arr[ptr+1]);
            }
            ptr++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}