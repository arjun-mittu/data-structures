#include<iostream>
#include<string>
using namespace std;
bool iscontain(string s,string check){
    for(int i=0;i<s.length();i++){
        if(s[i]==check[0]){
            return false;
        }
    }
    return true;
}
int main(){
    string s="aab";
    int len=s.length();
    int left=0;
    int right=0;
    string sub;
    int max=0;
    int mx;
    string a="a";
    if(iscontain(s,a)){
        cout<<"yes";
    }
   
    return 0;
}