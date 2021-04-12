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
node *midpoint(node *head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool palindrome(node *head,node *mid){
    if(head==NULL || head->next==NULL){
        return true;
    }
    while(head->next!=mid){
        if(head->data!=mid->data){
            return false;
        }
        head=head->next;
        mid=mid->next;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    node *head=take_input(n);
    node *mid=midpoint(head);
    if(n%2==0){
        mid=mid->next;
    }
    if(palindrome(head,mid)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}