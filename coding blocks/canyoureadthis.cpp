#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    char inp[1000];
    cin>>inp;
    int i=0;
    while(inp[i]!='\0'){
        if(isupper(inp[i]) && i>0){
            cout<<endl;
        }
        cout<<inp[i];
        i++;
    }
    return 0;
}