#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string text="abaacadbacad";
    string pat="aacax";
    //naive O(n*m)
    int n=text.size(),m=pat.size();
    for(int i=0;i<text.size();i++){
        if(text.substr(i,m)==pat){
            cout<<"yup "<<i;
            return 0;
        }
    }
    cout<<"not";
    return 0;
}