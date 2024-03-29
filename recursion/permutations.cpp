#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
void permute(char *in,int i){
    if(in[i]=='\0'){
        cout<<in<<" ,";
        return;
    }
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permute(in,i+1);
        swap(in[i],in[j]);
    }
}
void permute_unique(char *in,int i,set<string> &s){
    if(in[i]=='\0'){
        //cout<<in<<" ,";
        string t(in);
        s.insert(t);
        return;
    }
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permute_unique(in,i+1,s);
        swap(in[i],in[j]);
    }
}
int main(){
    char in[100];
    cin>>in;
    set<string> s;
    permute(in,0);
    cout<<endl;
    permute_unique(in,0,s);
    for(auto str:s){
        cout<<str<<",";
    }
    return 0;
}