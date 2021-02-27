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
//address of root node
node *buildtree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildtree();
    root->right = buildtree();
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
void print_inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}
void print_postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
void print_kthelevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    print_kthelevel(root->left, k - 1);
    print_kthelevel(root->right, k - 1);
    return;
}
void printalllevels(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_kthelevel(root, i);
        cout << endl;
    }
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
int count(node *root)
{
    // O(N)
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}
//check
int sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    //return ((root->data)+sum(root->left)+sum(root->left));
    return (root->data + leftsum + rightsum);
}

int diameter(node *root)
{
    //O(N*N)
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2; //root
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}
class pair_
{
public:
    int height;
    int diameter;
};
pair_ fastdiameter(node *root)
{
    pair_ p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    pair_ left = fastdiameter(root->left);
    pair_ right = fastdiameter(root->right);
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}
int sum_replacement(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    //recursive part
    int leftsum = sum_replacement(root->left);
    int rightsum = sum_replacement(root->right);
    int temp = root->data;
    root->data = leftsum + rightsum;
    return temp + root->data;
}
class hbpair
{
public:
    int height;
    bool balance;
};
hbpair isheightbalance(node *root)
{
    hbpair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }
    //recursive case
    hbpair left = isheightbalance(root->left);
    hbpair right = isheightbalance(root->right);
    p.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }
    return p;
}
node *buildtreefromarray(int *a, int s, int e)
{
    //base
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildtreefromarray(a, s, mid - 1);
    root->right = buildtreefromarray(a, mid + 1, e);
    return root;
}
node *createtreefromtrav(int *ino, int *pre, int s, int e)
{
    static int i = 0;
    //base case
    if (s > e)
    {
        return NULL;
    }
    //rec
    node *root = new node(pre[i]);
    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (ino[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createtreefromtrav(ino, pre, s, index - 1);
    root->right = createtreefromtrav(ino, pre, index + 1, e);
    return root;
}
void printrightview(node *root, int level, int &maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        //new level discovered
        cout << root->data << " ";
        maxlevel = level;
    }
    //right
    //left
    printrightview(root->right, level + 1, maxlevel);
    printrightview(root->left, level + 1, maxlevel);
}
void printatlevelK_below(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ,";
        return;
    }
    printatlevelK_below(root->left, k - 1);
    printatlevelK_below(root->right, k - 1);
    return;
}
int printatdistanceK(node *root, node *target, int k)
{
    //base case
    if (root == NULL)
    {
        return -1;
    }
    //reach the target node
    if (root == target)
    {
        printatlevelK_below(target, k);
        return 0;
    }
    //next step - ancestor
    int DL = printatdistanceK(root->left, target, k);
    if (DL != -1)
    {
        //two cases
        //ancestors itself or go to right
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printatlevelK_below(root->right, k - 2 - DL);
        }
        return 1 + DL;
    }
    int DR = printatdistanceK(root->right, target, k);
    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printatlevelK_below(root->left, k - 2 - DR);
        }
        return 1 + DR;
    }
    //node was not present in left and right subtree
    return -1;
}
node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a || root->data == b)
    {
        return root;
    }
    // search in left and right subtree
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);
    if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    if (leftans != NULL)
    {
        return leftans;
    }
    return rightans;
}
class pair_max_sum
{
public:
    int branchsum;
    int maxsum;
    pair_max_sum()
    {
        branchsum = 0;
        maxsum = 0;
    }
};
pair_max_sum maxsumpath(node *root)
{
    pair_max_sum p;
    if (root == NULL)
    {
        return p;
    }
    pair_max_sum left = maxsumpath(root->left);
    pair_max_sum right = maxsumpath(root->right);
    //construct two values
    int op1 = root->data;
    int op2 = left.branchsum + root->data;
    int op3 = right.branchsum + root->data;
    int op4 = right.branchsum + left.branchsum + root->data;
    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));
    //branch sum of the current root
    p.branchsum = max(left.branchsum, max(right.branchsum, 0)) + root->data;
    p.maxsum = max(left.maxsum, max(right.maxsum, current_ans_through_root));
    return p;
}
//finding level of a given node from any given root/any other node
int search_level(node *root, int key, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return level;
    }
    int left = search_level(root->left, key, level + 1);
    if (left != -1)
    {
        return left;
    }
    return search_level(root->right, key, level + 1);
}
int finddistance(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);
    int l1 = search_level(lca_node, a, 0);
    int l2 = search_level(lca_node, b, 0);
    return l1+l2;
}
int main()
{
    // node *root = buildtree();
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
    //cout << sum(root);
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
    /*int a[]={1,2,3,4,5,6,7};
    int n=7;
    node *root=buildtreefromarray(a,0,n-1);*/
    /* int ino[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    int n=sizeof(ino)/sizeof(int);
    node *root =createtreefromtrav(ino,pre,0,n-1);
    bfs(root);*/
    /*node *root = buildtree();
    int maxlevel = -1;
    bfs(root);
    cout<<endl;
    printrightview(root,0,maxlevel);*/
    node *root = buildtree();
    /*bfs(root);
    node *target = root->left->left;
    printatdistanceK(root,target,3);*/
    /* node *root=buildtree();
   node *lca_node= lca(root,6,9);
   cout<<"\n"<<lca_node->data;*/
    // cout<<"max sum path="<<maxsumpath(root).maxsum;
    cout<<"dist of "<<finddistance(root,6,9);
    return 0;
}