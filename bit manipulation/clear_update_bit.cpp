#include<iostream>
#include<math.h>
using namespace std;

void clearbit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
}
void updatebit(int &n,int i,int v){
    int mask=~(1<<i);
    int clear_bit_n=n&mask;
    n=clear_bit_n|(v<<i);

}
int clearlastibits(int n,int i){
    int mask=(-1<<i);
    return n&mask;
}
int clearrangeitoj(int n,int i,int j){
    int ones=(~0);
    int a=ones<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    int ans=n&mask;
    return ans;
}
int main(){
    int n=31;
    int i=1;
    int j=3;
    //cout<<clearlastibits(n,i)<<endl;
    cout<<clearrangeitoj(n,i,j);
    /*clearbit(n,2);
    cout<<n<<endl;
    updatebit(n,2,0);
    updatebit(n,3,1);*/
    cout<<n;
    return 1;
}