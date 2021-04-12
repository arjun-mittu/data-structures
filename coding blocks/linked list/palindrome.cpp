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
    cout<<endl;
    return;
}
node *reverse(node *head)
{
    node *c = head;
    node *n;
    node *prev = NULL;
    while (c != NULL)
    {
        n = c->next;
        c->next = prev;
        prev = c;
        c = n;
    }
    return prev;
}

bool palindrome(node *head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    node *p=head;
    node *rev=reverse(head);
    while(p!=NULL){
        if(p->data!=rev->data){
            return false;
        }
        p=p->next;
        rev=rev->next;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    node *head=take_input(n);
    if(palindrome(head)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}