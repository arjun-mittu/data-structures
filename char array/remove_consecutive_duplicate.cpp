#include<iostream>
#include<cstring>
using namespace std;
void remove_duplicate(char a[]){
    int l=strlen(a);
    if(l==1 || l==0){
        return;
    }
    int prev=0;
    for(int current=1;current<l;current++){
        if(a[current]!=a[prev]){
            prev++;
            a[prev]=a[current];
        }
    }
    a[prev+1]='\0';
    cout<<a;
    return;
}
int main(){
    char a[10];
    cin.getline(a,10);
    remove_duplicate(a);
    return 1;
}
