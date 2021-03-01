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
node *build_from_sorted_array(int arr[], int s, int e,int n)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    int sum = 0;
    for (int i = mid; i <= n-1; i++)
    {
        sum = sum + arr[i];
    }
    
    node *root = new node(sum);
    root->left = build_from_sorted_array(arr, s, mid - 1,n);
    root->right = build_from_sorted_array(arr, mid + 1, e,n);
    return root;
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
    int n;
    cin >> n;
    int ino[1000];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ino[i];
    }
    node *root = build_from_sorted_array(ino, 0, n - 1,n);
    print_preorder(root);
    return 0;
}