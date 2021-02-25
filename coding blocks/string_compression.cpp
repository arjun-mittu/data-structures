#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
void compress(string s,int i){
    if(i==s.length()){
        return;
    }
    int next_i=i;
    while(s[next_i]==s[next_i+1]){
        next_i++;
    }
    int diff=next_i-i+1;
    cout<<s[i]<<diff;
    compress(s,next_i+1);
}
int main()
{
    string s;
    cin>>s;
    compress(s,0);
    return 0;
}