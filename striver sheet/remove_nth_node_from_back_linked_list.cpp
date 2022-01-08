class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* h=head;
        while(h!=NULL){
            len++;
            h=h->next;
        }
        if(len==n) return head->next;
        int idx=len-n;
        h=head;
        for(int i=0;i<idx-1;i++){
            h=h->next;
        }
        ListNode *temp=h->next;
        h->next=temp->next;
        delete temp;
        return head;
    }
};