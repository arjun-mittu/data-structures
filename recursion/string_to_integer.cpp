#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int stringtoint(char *a,int n){
    if(n==0){
        return 0;
    }
    int digit=a[n-1]-'0'; //last digit subtracts ASCII values
    int small_ans=stringtoint(a,n-1);
    return small_ans*10+digit;
}
int main(){
    char a[]="1234";
    int len=strlen(a);
    int val=stringtoint(a,len);
    cout<<val;
    return 0;
}