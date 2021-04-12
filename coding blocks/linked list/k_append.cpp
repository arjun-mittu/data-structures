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
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
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
node* kthelement(node *head,int n,int k){
    node* prev=head;

    for(int i=0;i<(n-k-1);i++){
        prev=prev->next;
    }
    return prev;
}
int main(){
    int n;cin>>n;
    node *head=take_input(n);
    int k;cin>>k;
    if(k==0 || k%n==0){
        print(head);
        cout<<endl;
    }
    else{
        node *prev=kthelement(head,n,k%n);
        node *newhead=prev->next;
        prev->next=NULL;
        node *temp=newhead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        print(newhead);
        cout<<endl;
    }
    return 0;
}