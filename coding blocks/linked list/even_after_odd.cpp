#include <iostream>
#include<vector>
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
void insertattail(node *head, int d)
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
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return;
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
    return head;
}
node *merge(node *even, node *odd)
{
    node *temp = odd;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = even;
    cout<<"yo";
    return odd;
}
node* oddeven(node *head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //recursive case
    node *c = NULL;
    node *d = NULL;
    //even
    while (head != NULL)
    {
        if ((head->data) % 2 == 0)
        {
            insertattail(c, head->data);
        }
        else
        {
            insertattail(d, head->data);
        }
        head = head->next;
    }
    if (c != NULL && d != NULL)
    {
        node *temp = merge(c, d);
        return temp;
    }
    if (c == NULL)
    {
        return d;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    node *head=take_input(n);
    print(head);
    node *ans=oddeven(head);
    print(ans);
    return 0;
}