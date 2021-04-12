class Solution
{
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        Node *fast = head;
        Node *slow = head;
        bool flag = false;
        while (fast && slow && fast->next)
        {
            if (slow->next == fast->next->next)
            {
                flag = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
            /*if(slow->next==fast->next->next){
                flag=true;
                break;
            }*/
        }
        if (flag)
        {
            if (slow->next == head)
            {
                slow->next = NULL;
            }
            else
            {
                fast = fast->next->next;
                slow = head->next;
                while (fast->next != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                fast->next = NULL;
            }
        }
    }
};