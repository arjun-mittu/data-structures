#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int count=0;
char keypad[][10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void smart_keypad(char *inp,char *out,int i,int j){
    if(inp[i]=='\0'){
        out[j]='\0';
        cout<<out<<" ";
        count++;
        return;
    }
    int digit=inp[i]-'0';
    if(digit==0){
        smart_keypad(inp,out,i+1,j);
    }
    for(int idx=0;keypad[digit][idx]!='\0';idx++){
        out[j]=keypad[digit][idx];
        smart_keypad(inp,out,i+1,j+1);
    }
    return;
}

int main(){
    char inp[20];
    cin>>inp;
    char out[20];
    smart_keypad(inp,out,0,0);
    cout<<endl;
    cout<<count;
    return 0;
}