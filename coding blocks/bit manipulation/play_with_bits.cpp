#include<iostream>
using namespace std;
int count(int n){
    int ans=0;
    while(n>0){
        ans++;
        n=n&(n-1);
    }
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a==b){
            cout<<count(a)<<endl;
        }
        else{
            int sum=0;
            for(int i=a;i<=b;i++){
                sum+=count(i);
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}