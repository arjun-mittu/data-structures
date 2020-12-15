#include<iostream>
#include<cstring>
using namespace std;
int string_to_integer(char *a,int i){
    if(a[i]=='\0'){
        return 0;
    }
    int digit=a[i]-'0';
    return (digit*10)+string_to_integer(a,i+1);
}
int main(){
    char a[10];
    cin>>a;
    int n=strlen(a);
    int no=string_to_integer(a,0);
    cout<<no;
    return 0;
}