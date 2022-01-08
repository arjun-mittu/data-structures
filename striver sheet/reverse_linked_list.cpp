class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *shead=reverseList(head->next);
        ListNode *temp=head->next;
        head->next=NULL;
        temp->next=head;
        return shead;
    }
};