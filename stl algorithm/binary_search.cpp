#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,2,2,3,4};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    bool present=binary_search(arr,arr+n,key);
    if(present){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    auto it=lower_bound(arr,arr+n,key);
    auto it2=upper_bound(arr,arr+n,key);
    cout<<endl;
    cout<<it-arr<<endl;
    cout<<it2-arr<<endl;
    cout<<it2-it<<endl;
    return 0;
}