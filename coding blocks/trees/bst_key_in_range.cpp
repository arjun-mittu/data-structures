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
        //cout<<data;
        root->right = insertinBST(root->right, data);
    }
    return root;
}
node *build()
{
    int n;
    cin >> n;

    int data;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = insertinBST(root, data);
        //    cin>>data;
    }
    return root;
}
vector<int> pre;
void predorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre.push_back(root->data);
    predorder(root->left);
    predorder(root->right);
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        node *root = build();
        int k1, k2;
        cin >> k1 >> k2;
        cout << "# Preorder : ";
        predorder(root);
        sort(pre.begin(), pre.end());
        cout << endl;
        cout << "# Nodes within range are : ";

        t--;
    }
    return 0;
}