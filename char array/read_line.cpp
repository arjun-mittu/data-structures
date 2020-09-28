#include<iostream>
using namespace std;

void readline(char a[],int maxlen){
    int i=0;
    char ch=cin.get();
    while(ch!='\n'){
        a[i]=ch;
        i++;
        if(i==maxlen-1){
            break;
        }
        ch=cin.get();
    }
    a[i]='\0';
    cout<<a;
}
int main(){
    char a[10];
    //readline(a,10);
    cin.getline(a,10,'\n');
    cout<<a;
    return 1;
}