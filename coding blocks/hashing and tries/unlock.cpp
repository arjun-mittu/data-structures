#include<iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    unordered_map<ll,ll> m;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]=i;
    }
    for(ll i=n;i>=1 && k>0;i--){
        ll num=i;
        ll idx=m[num];
        ll best=n-num;
        if(idx!=best){
            swap(arr[idx],arr[best]);
            k--;
        }
        m[arr[best]]=best;
        m[arr[idx]]=idx;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    /*for(long long int i=0;i<n;i++){
        long long int data;
        cin>>data;
        m[i]=data;
    }

    for (long long int i = n - 1; i >= 0; i--)
    {
        if(k==0){
            break;
        }
        long long int d = m[i];
        long long int bestpos = n - d;
        if(i!=bestpos){
        if(k>0){
            swap(m[i],m[bestpos]);
            k--;
        }}
    }
    for (long long int i = 0; i < n; i++)
    {
        cout <<m[i]<<" ";
    }*/
    return 1;
}