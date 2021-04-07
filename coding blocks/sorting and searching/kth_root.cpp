#include<iostream>
using namespace std;
long long int get_power(long long int n,long long int k){
    long long int ans=1;
    while(k--){
        ans=ans*n;
    }
    return ans;
}
long long int get_ans(long long int n,long long int k){
    long long int s=0;
    long long int e=n;
    long long int ans=-1;
    while(s<=e){
        long long int mid=(s+e)/2;
        if(get_power(mid,k)==n){
            return mid;
        }
        else if (get_power(mid, k) < n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;cin>>n>>k;
        cout<<get_ans(n,k)<<endl;
    }
    return 0;
}