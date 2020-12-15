#include<iostream>
#include<cstring>
using namespace std;
int string_to_integer(char *a,int n){
    if(n==0){
        return 0;
    }
    int digit=a[n-1]-'0';
    return string_to_integer(a,n-1)*10+digit;
}
int main(){
    char a[10];
    cin>>a;
    int n=strlen(a);
    int no=string_to_integer(a,n);
    cout<<no;
    return 0;
}