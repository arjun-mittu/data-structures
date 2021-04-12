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
}
node *take_input()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        insertattail(head, d);
        cin >> d;
    }
    // for taking input till end of file
    /*while(cin>>d){
        insertathead(head,d);
       
    }*/
    return head;
}
node* getfast(node *head,int k){
    for(int i=0;i<k;i++){
        head=head->next;
    }
    return head;
}
int main(){
    node *head=take_input();
    int k;
    cin>>k;
    node *fast=getfast(head,k);
    node *slow=head;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    cout<<slow->data<<endl;
    return 0;
}