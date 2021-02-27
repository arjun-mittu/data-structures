#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
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
node *build()
{
    //-1 stop
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insertinBST(root, d);
        cin >> d;
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}
bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (data > root->data)
    {
        return search(root->right, data);
    }
    else
    {
        return search(root->left, data);
    }
}
node *deleteinBST(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = deleteinBST(root->left, data);
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
        root->right = deleteinBST(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteinBST(root->right, data);
        return root;
    }
}
bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;
}
class linkedlist
{
public:
    node *head;
    node *tail;
};
linkedlist flatten(node *root)
{
    linkedlist l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    // lead node
    if (root->left == NULL && root->right == NULL)
    {
        l.head = l.tail = root;
    }
    //left is not NULL
    if (root->left != NULL && root->right == NULL)
    {
        linkedlist leftll = flatten(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
        return l;
    }
    if (root->right != NULL && root->left == NULL)
    {
        linkedlist rightll = flatten(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
        return l;
    }
    //bith not NULL
    linkedlist leftll = flatten(root->left);
    linkedlist rightll = flatten(root->right);
    leftll.tail->right = root;
    root->right = rightll.head;
    l.head = leftll.head;
    l.tail = rightll.tail;
    return l;
}
int main()
{
    node *root = build();
    inorder(root);
    cout << endl;
    //bfs(root);
    /*int s;
    cin>>s;
    if(search(root,s)){
        cout<<"present";
    }
    else{
        cout<<"nope";
    }*/
    /*int s;
    cin>>s;
    root=deleteinBST(root,s);
    inorder(root);
    cout<<endl;
    bfs(root);*/
    /* if(isBST(root)){
        cout<<"yes";
    }
    else{
        cout<<"nope";
    }*/
    bfs(root);
    linkedlist l = flatten(root);
    node *temp = l.head;
    while (temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->right;
    }
    cout<<endl;
    return 0;
}