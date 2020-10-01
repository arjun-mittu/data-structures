#include<iostream>
using namespace std;
int clearrangeitoj(int n,int i,int j){
    int ones=(~0);
    int a=ones<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    int ans=n&mask;
    return ans;
}
int replacebit(int n,int m,int i,int j){
    int n_=clearrangeitoj(n,i,j);
    int ans=n_|(m<<i);
    return ans;
}
int main(){
    int n=15;
    int i=1;
    int j=3;
    int m=2;
    cout<<replacebit(n,m,i,j)<<endl;
    return 0;
}