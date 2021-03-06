#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        ll L;
        cin>>L;
        ll arr[L];
        unordered_map<ll,bool> m;
        for(ll i=0;i<L;i++){
            cin>>arr[i];
            m[arr[i]]=true;
        }
        ll q;
        cin>>q;
        while(q--){
            int d;
            cin>>d;
            if(m.count(d)==0){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}