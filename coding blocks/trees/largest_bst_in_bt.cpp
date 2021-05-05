#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;
    node(int d)
    {
        val = d;
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
class sol{
    public:
        int size;
        int min;
        int max;
        int isBST;
};
sol solve(node *root){
    
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