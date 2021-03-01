#include <bits/stdc++.h>
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
void printleftview(node *root,int level,int &maxlevel){
    if(root==NULL){
        return;
    }
    if(maxlevel<level){
        maxlevel=level;
        cout<<root->data<<" ";
    }
    printleftview(root->left,level+1,maxlevel);
    printleftview(root->right,level+1,maxlevel);
}
int main()
{
    node *root = build();
    int maxl = -1;
    printleftview(root, 0, maxl);
    return 1;
}