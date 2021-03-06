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
int check=0;
void print_below_k(node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        check=1;
        return;
    }
    print_below_k(root->left,k-1);
    print_below_k(root->right,k-1);
    return;
}
int print_distance_k(node *root,node *target,int k){
    if(root==NULL){
        return -1;     
    }
    if(root==target){
        print_below_k(root,k);
        return 0;
    }
    int DL=print_distance_k(root->left,target,k);
    if(DL!=-1){
        if(DL+1==k){
            check=1;
            cout<<root->data<<" ";
        }
        else{
            print_below_k(root->right,k-2-DL);
        }
        return 1+DL;
    }
    int DR=print_distance_k(root->right,target,k);
    if(DR!=-1){
        if (DR + 1 == k)
        {
            check=1;
            cout << root->data << " ";
        }
        else
        {
            print_below_k(root->left, k - 2 - DR);
        }
        return 1 + DR;
    }
    return -1;
}
node *target_search(node *root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
    return root;
    }
    else{
        node *found=target_search(root->left,target);
        if(found==NULL){
            found=target_search(root->right,target);
        }
        return found;
    }
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
    int T;
    cin >> T;
    while (T > 0)
    {
        check=0;
        int target_,k;
        cin>>target_>>k;
        node *target=target_search(root,target_);
        int ans=print_distance_k(root,target,k);
        if(!check){
            cout<<check;
        }
        cout<<endl;
        T--;
    }
    return 0; 
}