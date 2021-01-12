#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
void check_present(char *out,int size_window){
    string newout="";
    int ptr=0;
    while(out[ptr]!='\0'){
        newout+=out[ptr];
        ptr++;
    }
    int n=11;
    for(int i=0;i<n;i++){
        for(int l=0;l+size_window<searchIn[i].length();l++){
            string sub=searchIn[i].substr(l,size_window);
            if(newout==sub){
                cout<<searchIn[i]<<endl;
            }
        }
    }
}

char keypad[][10]={" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void smart_keypad(char *inp,char *out,int i,int j){
    if(inp[i]=='\0'){
        out[j]='\0';
       // cout<<out<<" "<<j<<endl;
       check_present(out,j);
        return;
    }
    int digit=inp[i]-'0';
    /*if(digit==0){
        smart_keypad(inp,out,i+1,j);
    }*/
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
    return 0;
}