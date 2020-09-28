#include<iostream>
#include<math.h>
using namespace std;
int reverse_num(int n){
    int m=n;
    int div=10;
    int val;
    int rev=0;
    while(m!=0){
        val=m%10;
        rev=rev*10+val;
        m=m/10;
    }
    return rev;
}
int main(){
    int n;
    cin>>n;
    int reverse;
    if(n<0){
        
        reverse=reverse_num(n);
        
    }
    else{
        reverse=reverse_num(n);
    }
    cout<<reverse;
    return 0;
}
