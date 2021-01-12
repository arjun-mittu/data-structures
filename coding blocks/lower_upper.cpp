#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    char s;
    cin>>s;
    if(isupper(s)){
        putchar(tolower(s));
    }
    else if(islower(s)){
        putchar(toupper(s));
    }
    else{
        cout<<"Invalid";
    }
    return 0;
}