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
void printrightview(node *root, int level, int &maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        //new level discovered
        cout << root->data << " ";
        maxlevel = level;
    }
    //right
    //left
    printrightview(root->right, level + 1, maxlevel);
    printrightview(root->left, level + 1, maxlevel);
}
int main()
{
    node *root = build();
    int maxl=-1;
    printrightview(root,0,maxl);
    return 1;
}