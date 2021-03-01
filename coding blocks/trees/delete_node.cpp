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
node *insertinBST(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    //rec case
    if (data <= root->data)
    {
        root->left = insertinBST(root->left, data);
    }
    else
    {
        root->right = insertinBST(root->right, data);
    }
    return root;
}
void bfs(node *root)
{
    queue<node *> q; //contains address
    q.push(root);
    q.push(NULL); //for next level so to add to next line
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL); // adding at end for next levels
            }
        }
        else
        {
            cout << f->data << " , ";
            q.pop();
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}
node *deleteinBST_use(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = deleteinBST_use(root->left, data);
        return root;
    }
    else if (data == root->data)
    {
        //found the node to delete 3 cases
        //node with 0 children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //node with 1 children
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // node with 2 children
        node *replace = root->right;
        //inorder successor from right subtree
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteinBST_use(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteinBST_use(root->right, data);
        return root;
    }
}
void print_preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //print root first followed by subtrees(children)
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        int arr[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int m;
        cin >> m;
        int del[1000];
        for (int i = 0; i < m; i++)
        {
            cin >> del[i];
        }
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            root = insertinBST(root, arr[i]);
        }
         //bfs(root);
        for (int i = 0; i < m; i++)
        {
            root = deleteinBST_use(root, del[i]);
        }
        print_preorder(root);
        cout<<endl;
        t--;
    }
    return 0;
}