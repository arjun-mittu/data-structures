#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        //int nchild;
        node *left;
        node *right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
node *buildtree(){
    int data;
    cin>>data;
    int nochild;
    cin>>nochild;
   node* root=new node(data);
    if(nochild==2){
        root->left=buildtree();
        root->right = buildtree();
        return root;
    }
    if(nochild==1){
        root->left=buildtree();
        return root;
    }
    if (nochild == 0)
    {
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    return root;
}
int ans=0;
void solveAgain(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        ans = ans + root->data;
    }
    solveAgain(root->left, k - 1);
    solveAgain(root->right, k - 1);
}
int main(){
    node *root;
    root=buildtree();
    int k;
    cin>>k;
    solveAgain(root, k);
    cout << ans;
    return 0;
}