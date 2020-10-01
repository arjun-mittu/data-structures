#include<iostream>
using namespace std;
//first o(log(n))
int countbits(int n){
    int ans=0;
    while(n>0){
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}
//second method o(number of set bits)
int countbitsfast(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main(){
    int n=13;
    cout<<countbits(n)<<endl;
    cout<<countbitsfast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}