class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        swap(temp->val,node->val);
        node->next=temp->next;
        delete temp;
    }
};