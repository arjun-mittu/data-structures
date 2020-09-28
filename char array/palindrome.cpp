#include<iostream>
#include<cstring>
using namespace std;
bool ispalin(char a[]){
    int i=0;
    int j=strlen(a)-1;
    while(i<j){
        if(a[i]==a[j]){
            i++;j--;
        }
        else {
            return false;
        }
    }
    return true;
}
int main(){
    char a[10];
    cin.getline(a,10);
    if(ispalin(a)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 1;
}
