#include<bits/stdc++.h>
using namespace std;
vector<string> get_tf(string a){
    vector<string> op;
    string s;
    stringstream word(a);
    while(word>>s){
        if(s=="true" || s=="false"){
            op.push_back(s);
        }
    }
    return op;
}
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    vector<string> sa=get_tf(a);
    vector<string> sb=get_tf(b);
    if(sa==sb){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}