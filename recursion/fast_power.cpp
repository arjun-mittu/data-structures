#include<iostream>
using namespace std;
int power(int a,int n){
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}
int fast_power(int a,int n){
    if(n==0){
        return 1;
    }
    int smaller_ans=fast_power(a,n/2);
    smaller_ans*=smaller_ans;
    if(n & 1){
        return smaller_ans*a;
    }
    return smaller_ans;
}
 int main(){
     cout<<fast_power(2,4);
     return 0;
 }