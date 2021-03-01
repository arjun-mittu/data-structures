#include <iostream>
#include <algorithm>
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
node *build(int *pre, int *ino, int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }
    node *root = new node(pre[i]);
    int idx = -1;
    for (int j = s; j <= e; j++)
    {
        if (pre[i] == ino[j])
        {
            idx = j;
        }
    }
    i++;
    root->left = build(pre, ino, s, idx - 1);
    root->right = build(pre, ino, idx + 1, e);
    return root;
}
int bst_in_tree(node *root){
    if(root==NULL){
        return 0;
    }
    bst_in_tree(root->left);
    bst_in_tree(root->data);
    if(root->left && root->right && root->left->data<=)
}
int main()
{
    int n;
    cin >> n;
    int pre[100];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    int ino[100];
    for (int i = 0; i < n; i++)
    {
        cin >> ino[i];
    }
    node *root = build(pre, ino, 0, n - 1);
    
    return 0;
}