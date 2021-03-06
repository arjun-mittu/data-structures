#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<vector>
#include<set>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    ll arr1[n],arr2[n];
    vector<ll> com;
    unordered_map<ll> m;
    for(ll i=0;i<n;i++){
        cin>>arr1[i];
        
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> arr2[i];
        if(s.find(arr2[i])!=s.end()){
            com.push_back(arr2[i]);
        }
    }
    for(auto x:com){
        cout<<x;
    }
    

    return 0;
}