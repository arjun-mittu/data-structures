#include<iostream>
#include<map>
#include<vector>
#include<queue>
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
node *build()
{
    int d;
    cin >> d;
    queue<node *> q;
    node *root = new node(d);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int d1, d2;
        cin >> d1 >> d2;
        if (d1 != -1)
        {
            temp->left = new node(d1);
            q.push(temp->left);
        }
        if (d2 != -1)
        {
            temp->right = new node(d2);
            q.push(temp->right);
        }
    }
    return root;
}
void verticalview(node *root,int d,map<int,vector<int>> &m){
    if(root==NULL){
        return ;
    }
    m[d].push_back(root->data);
    verticalview(root->left,d-1,m);
    verticalview(root->right,d+1,m);
    return;
}
        
int main(){
    int n;
    cin>>n;
    node *root=build();
    map<int,vector<int>> m;
    verticalview(root,0,m);
    for (auto p : m)
    {
        //cout << p.first << "->";
        for (int x : p.second)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}