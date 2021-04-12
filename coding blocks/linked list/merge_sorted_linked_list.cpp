#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertattail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    //if maintaing a tail pointer then tail=tail->next;
}
node *take_input(int n)
{

    node *head = NULL;
    while (n--)
    {
        int val;
        cin >> val;
        insertattail(head, val);
    }
    // for taking input till end of file
    /*while(cin>>d){
        insertathead(head,d);
       
    }*/
    return head;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return;
}
node *merge(node *a,node *b){
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n1,n2;
        cin>>n1;
        node *head1=take_input(n1);
        cin>>n2;
        node *head2=take_input(n2);
        node *head3=merge(head1,head2);
        print(head3);
        cout<<endl;
    }
    
}