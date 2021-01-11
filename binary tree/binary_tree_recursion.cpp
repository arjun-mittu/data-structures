#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
//address of root node
node* buildtree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node *root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void print_preorder(node *root){
    if(root==NULL){
        return ;
    }
    //print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_inorder(node *root){
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
void print_postorder(node *root){
    if(root==NULL){
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}
int height(node *root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
void print_kthelevel(node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    print_kthelevel(root->left,k-1);
    print_kthelevel(root->right,k-1);
    return;
}
void printalllevels(node *root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        print_kthelevel(root,i);
        cout<<endl;
    }
}
void bfs(node *root){
    queue<node*> q; //contains address
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<f->data<<" , ";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }}
    }
    return;
}
int count(node *root){
    // O(N)
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}
//check
int sum(node *root){
    if(root==NULL){
        return 0;
    }
    int leftsum=sum(root->left);
    int rightsum=sum(root->right);
    //return ((root->data)+sum(root->left)+sum(root->left));
    return (root->data + leftsum + rightsum);
}

int diameter(node *root){
    //O(N*N)
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
class pair_{
    public:
        int height;
        int diameter;
};
pair_ fastdiameter(node *root){
    pair_ p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }
    pair_ left=fastdiameter(root->left);
    pair_ right=fastdiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}
int sum_replacement(node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    //recursive part
    int leftsum=sum_replacement(root->left);
    int rightsum=sum_replacement(root->right);
    int temp=root->data;
    root->data=leftsum+rightsum;
    return temp+root->data;
}
class hbpair{
    public:
    int height;
    bool balance;
};
hbpair isheightbalance(node *root){
    hbpair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    //recursive case
    hbpair left=isheightbalance(root->left);
    hbpair right=isheightbalance(root->right);
    p.height=max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    return p;
}

int main(){
    node *root=buildtree();
   /* print_preorder(root);
    cout<<endl;
    print_inorder(root);
    cout<<endl;
    print_postorder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    print_kthelevel(root,3);cout<<endl;
    printalllevels(root);
    cout<<endl;
    bfs(root);
    cout<<endl;
    cout<<count(root);
    cout<<endl;*/
    cout<<sum(root);
    //cout<<diameter(root)<<endl;
    /*pair_ p=fastdiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;*/
    //bfs(root);
    //sum_replacement(root);
    //bfs(root);
    /*if(isheightbalance(root).balance){
        cout<<"balanced";
    }
    else{
        cout<<"unbalanced";
    }*/
    return 0;
}