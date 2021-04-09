#include<iostream>
using namespace std;
#define ll long long
ll power_optimised(ll a,ll n,ll c){
    ll ans=1;
    while(n>0){
        ll last_bit=(n&1);
        if(last_bit){
            ans=(ans*a)%c;
        }
        a=(a*a)%c;
        n=n>>1;
    }
    return ans;
}
int main(){
    ll a,b,c;
	cin>>a>>b>>c;
    ll power=power_optimised(a,b,c);
	cout<<power%c;
    return 0;
}