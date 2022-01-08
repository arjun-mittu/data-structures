class Solution {
public:
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* shead=rev(head->next);
        ListNode* temp=head->next;
        head->next=NULL;
        temp->next=head;
        return shead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //l1=rev(l1);
        //l2=rev(l2);
        int sum=0;
        int c=0;
        ListNode* res=NULL;
        ListNode* temp;
        ListNode* curr=NULL;
        while(l1!=NULL || l2!=NULL){
            sum=c+(l1?l1->val:0)+(l2?l2->val:0);
            c=(sum>=10)?1:0;
            sum=sum%10;
            temp=new ListNode(sum);
            if(res==NULL) res=temp;
            else curr->next=temp;
            curr=temp;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(c>0){
            temp=new ListNode(c);
            curr->next=temp;
            curr=temp;
        }
        return res;
    }
};