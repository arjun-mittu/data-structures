#include<iostream>
#include<cstring>
using namespace std;
void char_format(char *a,int i){
    if(a[i]=='\0' || a[i+1]=='\0'){
        return;
    }
    if(a[i]==a[i+1]){
        int j=i+1;
        while(a[j]!='\0'){
            j++;
        }
        while(j>=i+1){
            a[j+1]=a[j];
            j--;
        }
        a[i+1]='*';
        char_format(a,i+2);
    }
    else{
        char_format(a,i+1);
    }
    return;
}
int main(){
    char a[10];
    cin>>a;
    char_format(a,0);
    cout<<a;
    return 0;
}