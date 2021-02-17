#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>
using namespace std;
string replace_with(string s,int k,int c){
    int i=0;
    while(i<s.length()){
        if(k==0){
            break;
        }
        else{
            if(c=='a' && s[i]=='a'){
                s[i]='b';
                k--;
            }
            if(c=='b' && s[i]=='b'){
                s[i]='a';k--;
            }
        }
        i++;

    }
    return s;
}
int main()
{
    int k;
    string  s;
    cin>>k;
    cin>>s;
    int c_a=0;int c_b=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            c_a++;
        }
        if(s[i]=='b'){
            c_b++;
        }
    }
    int max_count=max(c_a,c_b);
    int min_count=min(c_a,c_b);
    /*if(min_count<=k){
        cout<<s.length();
    }
    else{
        cout<<max_count+k;
    }*/
    string s_new;
    if(min_count==c_a){
        s_new=replace_with(s,k,'a');
    }
    if (min_count == c_b)
    {
        s_new = replace_with(s, k, 'b');
    }
    int c_a_new = 0;
    int c_b_new = 0;
    for (int i = 0; i < s_new.length(); i++)
    {
        if (s_new[i] == 'a')
        {
            c_a_new++;
        }
        if (s_new[i] == 'b')
        {
            c_b_new++;
        }
    }
    cout<<max(c_b_new,c_a_new);
    return 0;
}