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
node *build_from_sorted_array(int arr[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node *root=new node(arr[mid]);
    root->left=build_from_sorted_array(arr,s,mid-1);
    root->right=build_from_sorted_array(arr,mid+1,e);
    return root;
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
        for (int i = 0; i <n;i++){
            cin>>arr[i];
        }
        node *root=build_from_sorted_array(arr,0,n-1);
        print_preorder(root);
        cout<<endl;
        t--;
    }
    return 0;
}