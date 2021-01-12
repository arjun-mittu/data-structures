#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    int count[256]={0};
    string s;
    cin>>s;
    int len=s.length();
    int max=0;
    char result;
    for(int i=0;i<len;i++){
        count[s[i]]++;
        if(max<count[s[i]]){
            max=count[s[i]];
            result=s[i];
        }
    }
    cout<<result;
    return 0;
}