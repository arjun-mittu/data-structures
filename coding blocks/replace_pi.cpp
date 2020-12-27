#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void replace_pi(char *a,int i){
    if(a[i]=='\0' || a[i+1]=='\0'){
        return;
    }
    if(a[i]=='p' && a[i+1]=='i'){
        int j=i+2;
        while(a[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            a[j+2]=a[j];
            j--;
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        replace_pi(a,i+4);
    }
    else{
        replace_pi(a,i+1);
    }
    return;

}

int main(){
    int n;
    cin>>n;
    int case1=0;
    while(case1<n){
    char a[100];
    cin>>a;
    replace_pi(a,0);
    cout<<a<<endl;
    case1++;
    }
    return 0;
}