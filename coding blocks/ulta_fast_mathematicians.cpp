#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T>0){
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.length();i++){
            cout<<abs(s1[i]-s2[i]);
        }
        cout<<endl;
        T--;
    }
    return 0;
}