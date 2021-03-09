#include <iostream>
//#include <unordered_map>
#include <map>
#include<cstring>
#include<string>
using namespace std;
class Node
{
public:
    char data;
    map<char, Node *> children;
    bool terminal;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};
class Trie
{
public:
    Node *root;
    // int cnt;
    Trie()
    {
        root = new Node('\0');
        // cnt = 0;
    }
    void insert(string w)
    {
        Node *temp = root;
        for (int i = 0;i< w.length(); i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
};
void print(Node *root,string s){
    if(root->children.empty()){
        cout<<s<<endl;
        return ;
    }
    if(root->terminal){
        cout<<s<<endl;
    }
    Node *t;
    string w;
    for(auto p=root->children.begin();p!=root->children.end();p++){
        t=root->children[p->first];
        w=s+t->data;
        print(t,w);
    }
}
bool searchprefix(Node *root,string s){
    Node *temp=root;
    for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{
                return false;
            }
    }
    print(temp,s);
    return true;
}
int main(){
    Trie *t=new Trie();
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        t->insert(arr[i]);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string temp;
        cin>>temp;
        bool p=searchprefix(t->root,temp);
        if(p==false){
            cout<<"No suggestions"<<endl;
            t->insert(temp);
        }
    }
    return 0;
}