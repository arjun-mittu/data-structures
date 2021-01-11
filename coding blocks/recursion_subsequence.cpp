#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(string inp,int j,int &count, string ans){
    if(j == inp.length()){
        cout<<ans<<" ";
        count++;
        return;
    }
    generate_subsequence(inp,j + 1,count, ans);
    generate_subsequence(inp,j+1,count, ans + inp[j]);
    //generate_subsequence(inp,j + 1,count, ans);
}
int main(){
    string inp;
    cin>>inp;
    int count=0;
    generate_subsequence(inp,0,count, "");
    cout<<endl;
    cout<<count;
    return 0;
}