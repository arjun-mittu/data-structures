#include<iostream>
#include<cstring>
using namespace std;
void replacepi(char a[], int i){
    if(a[i]=='\0' || a[i+1]=='\0'){
        return;
    }
    //look for pi at current location
    if(a[i]=='p' && a[i+1]=='i'){
        //shifting and replacement with 3.14
        int j=i+2;
        //take j to end of array
        while(a[j]!='\0'){
            j++;
        }
        //shifting (right to left)
        while(j>=i+2){
            a[j+2]=a[j];
            j--;
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        replacepi(a,i+4);
    }
    else{
        // go to next pos
        replacepi(a,i+1);
    }
    return;
}
int main(){
    char a[100];
    cin>>a;
    replacepi(a,0);
    cout<<a<<endl;
    return 0;
}