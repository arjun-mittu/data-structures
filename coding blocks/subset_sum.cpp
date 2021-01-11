#include<iostream>
#include<algorithm>
using namespace std;
void print_arr(int *out,int n){
   // int n=sizeof(out)/sizeof(out[0]);
    for(int i=0;i<n;i++){
        cout<<out[i];
    }
}
void check_sum(int *arr,int i,int j,int *out,int n){
    if(i==n){
        print_arr(out,j);
    }
    out[j]=arr[i];
    check_sum(arr,i+1,j+1,out,n);
    check_sum(arr,i+1,j,out,n);
}
int main(){
    int t;
    cin>>t;
    for(int in=0;in<t;in++){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int *out=new int[n];
        check_sum(arr,0,0,out,n);
    }
}