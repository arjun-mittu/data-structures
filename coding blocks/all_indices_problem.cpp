#include<iostream>
using namespace std;
void all_indices(int *a,int *out,int n,int i,int m,int outi){
    if(i==n){
        return;
    }
    if(a[i]==m){
        out[outi]=i;
        cout<<i<<" ";
        all_indices(a,out,n,i+1,m,outi+1);
    }
    else{
    all_indices(a,out,n,i+1,m,outi);}
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int output[100];
    all_indices(arr,output,n,0,m,0);
    return 0;
}