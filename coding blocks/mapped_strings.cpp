#include<iostream>
using namespace std;
void map_string(char *a,char *out,int i,int j){
    if(a[i]=='\0'){
        out[j]=a[i];
        cout<<out<<endl;
        return;
    }
    int digit=a[i]-'0';
    int ch=digit+'A'-1;
    out[j]=ch;
    map_string(a,out,i+1,j+1);
    if(a[i+1]!='\0'){
        int second=a[i+1]-'0';
        int number=digit*10+second;
        if(number<=26){
            ch=number+'A'-1;
            out[j]=ch;
            map_string(a,out,i+2,j+1);
        }
    }
}
int main(){
    char a[100];
    cin>>a;
    char out[100];
    map_string(a,out,0,0);
}