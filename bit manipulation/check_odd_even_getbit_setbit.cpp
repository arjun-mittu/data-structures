#include<iostream>
#include<math.h>
using namespace std;
bool isOdd(int n){
    return (n&1);
}
int getbit(int n,int i){
    int mask=(1<<i);
    int bit=(n&mask)>0? 1:0;
    return bit;
}
int setbit(int n,int i){
    int mask=(1<<i);
    int ans=n|mask;
    return ans;
}
void clearbit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
}
int main(){
    int n=5;
    cout<<isOdd(n)<<endl;
    cout<<getbit(n,1)<<endl;
    n=setbit(n,1);
    cout<<n;
    return 1;
}