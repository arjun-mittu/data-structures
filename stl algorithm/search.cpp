#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    auto it=find(arr,arr+n,key);
    cout<<it-arr;
    return 0;
}