#include<iostream>
#include<cstring>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    char a[10];
    char large[10];
    int len=0;
    int larg_len=0;
    cin.get();
    for(int i=0;i<n;i++){
        cin.getline(a,10);
        cout<<a;
        len=strlen(a);
        if(len>larg_len){
            larg_len=len;
            strcpy(large,a);
        }
    }
    cout<<large<<" "<<larg_len;
    return 0;
}
