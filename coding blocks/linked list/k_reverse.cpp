#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int d){
            data=d;
            next=NULL;
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
        cin>>val;
        insertattail(head,val );
    }
    // for taking input till end of file
    /*while(cin>>d){
        insertathead(head,d);
       
    }*/
    return head;
}
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
node *reverse_k(node *head,int k)
{
    node *c = head;
    node *prev = NULL;
    node *n;
    int count=0;
    while (count<k)
    {
        // save next node
        n = c->next;
        // make the current node point to prev
        c->next = prev;
        // update p and c take them 1 step forward
        prev = c;
        c = n;
        count++;
    }
    if(n!=NULL){
        head->next=reverse_k(n,k);
    }
    return prev;
}
/*node *reversek(node *head,int n,int k){
    if (!head || !head->next || k == 1)
        return head;
    

    node *prev = nullptr, *next, *newHead;
    node *t1 = nullptr, *t2 = head;
    node *curr = head;

    while (n >= k)
    {
        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (!newHead)
            newHead = prev;
        if (t1)
            t1->next = prev;
        t2->next = curr; // n is not multiple of k
        t1 = t2;
        t2 = curr;
        prev = nullptr;
        n -= k;
    }
    return newHead;
}*/
int main(){
    int n,k;
    cin>>n>>k;
    node *head;
    head=take_input(n);
    head=reverse_k(head,k);
    print(head);
    cout<<endl;
    return 0;
}