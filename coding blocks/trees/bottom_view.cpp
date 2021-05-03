#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *build()
{
    int d;
    cin >> d;
    queue<node *> q;
    node *root = new node(d);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int d1, d2;
        cin >> d1 >> d2;
        if (d1 != -1)
        {
            temp->left = new node(d1);
            q.push(temp->left);
        }
        if (d2 != -1)
        {
            temp->right = new node(d2);
            q.push(temp->right);
        }
    }
    return root;
}
void bottom_view(node *root,int hd,int height,map<int,pair<int,int>> &m){
    if(root==NULL) return ;
    if(m.find(hd)==m.end()){
        m[hd]={root->data,height};
    }
    else{
        if(m[hd].second<=height){
            m[hd]={root->data,height};
        }
    }
    bottom_view(root->left,hd-1,height+1,m);
    bottom_view(root->right,hd+1,height+1,m);
}

int main()
{
    node *root = build();
    map<int, pair<int,int>> m;
    bottom_view(root,0,0,m);
    for(auto x:m){
        cout<<x.second.first<<" ";
    }
    return 0;
}