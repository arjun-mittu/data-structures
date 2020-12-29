#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<char> q;
    int freq[27]={0};
    //running stream until a '.'
    char ch;
    cin>>ch;
    while(ch!='.'){
        //insert in q and f tables
        q.push(ch);
        int idx=ch-'a';
        freq[idx]++;
        //query
        while(!q.empty()){
            if(freq[q.front()-'a']>1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        // q is empty
        if(q.empty()){
        cout<<"-1"<<endl;}
        cin>>ch;
    }
    return 0;
}