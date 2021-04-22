class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        Node *first = head;
        Node *prev;
        Node *curr;
        while (first != NULL)
        {
            prev = first;
            curr = first->next;
            while (curr != NULL)
            {
                if (curr->data == first->data)
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
                else
                {
                    curr = curr->next;
                    prev = prev->next;
                }
            }
            first = first->next;
        }
        return head;
    }
};