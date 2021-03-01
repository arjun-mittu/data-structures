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
node *build(int *pre,int *ino,int s,int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node *root=new node(pre[i]);
    int idx=-1;
    for(int j=s;j<=e;j++){
        if(pre[i]==ino[j]){
            idx=j;
        }
    }
    i++;
    root->left=build(pre,ino,s,idx-1);
    root->right = build(pre, ino, idx+1, e);
    return root;
}
void preorder(node *root){
    if(root==NULL){
        return;
    }
    if(root->left){
        cout<<root->left->data;
    }
    else{
        cout<<"END";
    }
    cout << " => "<<root->data<<" <= ";
    if (root->right)
    {
        cout << root->right->data;
    }
    else
    {
        cout << "END";
    }
    cout<<endl;
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n;
    cin>>n;
    int pre[100];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    int m;cin>>m;
    int ino[100];
    for (int i = 0; i < m; i++)
    {
        cin >> ino[i];
    }
    node *root=build(pre,ino,0,n-1);
    preorder(root);
    return 0;
}