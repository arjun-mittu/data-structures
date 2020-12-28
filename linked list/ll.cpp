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
// linked class(object oriented)
/*
class linkedlist{
    node *head;
    node *tail;
public:
    linkedlist(){

    }
    void insert(int d){

    }
};
*/

//functions (procedural)
void biuld(){

}
//passing pointer by reference
void insertathead(node *&head,int d){
    if(head==NULL){
        head =new node(d);
        return;
    } 
    node *n=new node(d);
    n->next=head;
    head=n;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}
int length(node *head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}
void insertattail(node *&head ,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=new node(d);
    //if maintaing a tail pointer then tail=tail->next;
}
void insertinmiddle(node *&head,int d,int p){
    if(head==NULL || p==0){
        insertathead(head,d);
        return;
    }
    else if(p>length(head)){
        insertattail(head,d);
    }
    else{
        //p-1 jumps
        int jump=1;
        node *temp=head;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        node *n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }

}
void deletehead(node *&head){
    if(head==NULL){
        return;
    }
    node *temp=head;// my approach
    head=head->next;
    delete temp;
    /*node *temp=head->next;
    delete head;
    head=temp;*/
}
//void deleteinmiddle
//void delelteatend

bool search(node *head,int key){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

//recursively
bool searchrec(node *head,int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }
    else{
        return searchrec(head->next,key);
    }
}

node* take_input(){
    int d;
    cin>>d;
    node *head=NULL;
    while(d!=-1){
        insertathead(head,d);
        cin>>d;
    }
    // for taking input till end of file
    /*while(cin>>d){
        insertathead(head,d);
       
    }*/
    return head;
}

ostream& operator<<(ostream &os, node *head){
    print(head);
    return os;
}
istream& operator>>(istream &is,node *&head){
    head=take_input();
    return is;
}
void reverse(node *&head){
    node *c=head;
    node *prev=NULL;
    node *n;
    while(c!=NULL){
        // save next node
        n=c->next;
        // make the current node point to prev
        c->next=prev;
        // update p and c take them 1 step forward
        prev=c;
        c=n;
    }
    head=prev;
}
node *recreverse(node *head){
    //smallest linked list
    if(head->next==NULL || head==NULL){
        return head;
    }

    // rec case
    node *shead=recreverse(head->next);
    /*node *temp=shead;
    while(temp->next!=NULL){
        temp=temp->next;
    }*/
    // modfied approach
    node *temp=head->next;
    head->next=NULL;
    temp->next=head;
    return shead;

}
node *midpoint(node *head){
    //it check 0 node or no nodes
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node *merge(node *a,node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    node *c;
    if(a->data < b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
node *mergesort(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    //rec case
    //1. break
    node *mid=midpoint(head);
    node *a =head;
    node *b=mid->next;
    mid->next==NULL;
    //2. rec sort
    a=mergesort(a);
    b=mergesort(b);
    node *c =merge(a,b);
    return c;
}
bool detectcycle(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false; 
}
int main(){
    //node *head=take_input();
    //node *head2=take_input();
    node *head;
  //  node *head2;
    cin>>head;
    cout<<head<<endl;
    node* new_head=mergesort(head);
    cout<<new_head<<endl;
    //node *newhead=merge(head,head2);
    //cout<<newhead;
    //reverse(head);
    //head=recreverse(head);
   // node *mid=midpoint(head);
    //cout<<mid->data<<endl;
    //cout<<head;
    //node *head2;
    //cin>>head>>head2;
    //cout<<head<<head2;
    //cout<<head2;
    //node *head=NULL;
    /*insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,0);
    insertinmiddle(head,4,3);
    insertattail(head,7);
    print(head);
    deletehead(head);*/
    /*print(head);
    if(searchrec(head,77)){
        cout<<"found";
    }
    else{
        cout<<"not";
    }*/

    return 0;
}