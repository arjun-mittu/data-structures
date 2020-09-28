#include<iostream>
#include<string>
using namespace std;
int main(){
    string s0;
    string s1("hello");
    string s2="hello";
    string s3(s2);
    string s4=s3;
    char a[]={'a','b'};
    string s5(a);
    if(s0.empty()){
        cout<<"emoyty\n";
    }
    s0.append("abcd");
    cout<<s0<<endl;
    s0+="python";
    cout<<s0<<endl;
    s0.clear();
    cout<<s0.length()<<endl;
    s0="apple";
    s1="mango";
    cout<<s1.compare(s0)<<endl;

    string s;
    s="i love apples";
    int idx=s.find("apple");
    cout<<idx<<endl;
    string word="apple";
    int len=word.length();
    s.erase(idx,len);
    cout<<s;
    cout<<endl;
    for(int i=0;i<s1.length();i++){
        cout<<s1[i]<<":";
    }
    cout<<endl;
    for(auto it=s1.begin();it!=s1.end();it++){
        cout<<(*it)<<",";
    }
    cout<<endl;
    for(string::iterator it=s1.begin();it!=s1.end();it++){
        cout<<(*it)<<",";
    }
    cout<<endl;
    for(auto c:s1){
        cout<<c<<".";
    }
    return 0;
}