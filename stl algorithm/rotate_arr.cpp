#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    rotate(arr,arr+2,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    vector <int> i{1,2,3,4,5};
    rotate(i.begin(),i.begin()+2,i.end());
    for(auto x:i){
        cout<<x<<" ";
    }
    cout<<endl;
    next_permutation(i.begin(),i.end());
    for(int x:i){
        cout<<x<<" ";
    }
    return 0;
}