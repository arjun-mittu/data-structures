#include<iostream>
using namespace std;
bool check_power(int n){
    int m=1;
    while(n>m){
        if(n==m){
            return true;
        }
        m=m<<1;
    }
    return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        /*int dp[n+1];
        dp[0]=0;
        if(n>=1){dp[1]=1;}
        if(n>=2){dp[2]=1;}
        if(n>=3){dp[3]=2;}

        if(n<=3){
            cout<<dp[n]<<endl;
        }
        if(check_power(n)){
            cout<<1<<endl;
            dp[n]=1;
        }
        else{
            
        }*/
        cout << __builtin_popcount(n) << endl;
    }
    return 0;
}