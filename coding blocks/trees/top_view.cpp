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
void top_view(node *root)
{
    if (root == NULL)
    {
        return;
    }
    top_view(root->left);
    cout << root->data<<" ";
    return;
}
int main()
{
    node *root = build();
    top_view(root);
    root=root->right;
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
    return 0;
}