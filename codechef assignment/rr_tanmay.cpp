#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
    public:
    int pid;
    int at;
    int bt;
    LinkedList *next;
    LinkedList(int pid,int at,int bt)
    {
        this -> pid = pid;
        this -> at = at;
        this -> bt = bt;
        this -> next = NULL;
    }
};
LinkedList* create_List(int **arr,int n,int m)
{
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = i+1 ; j < n ;j++)
        {
            if( arr[i][1] > arr[j][1])
            {
                int k;
                for(int x = 0 ; x < m ;x++){
                    k=arr[i][x];
                    arr[i][x]=arr[j][x];
                    arr[j][x]=k;
                }
            }
        }
    }

    LinkedList *first = NULL;
    LinkedList *last = NULL;
    
    for(int i = 0 ; i < n ;i++)
    {
        LinkedList *newLinkedList = new LinkedList(arr[i][0],arr[i][1],arr[i][2]);
        if(first == NULL)
        {
            first = last = newLinkedList;
        }
        else
        {
            last -> next = newLinkedList;
            last = newLinkedList;
        }
    }
    return first;
}
void rr(LinkedList *first1 , LinkedList *first2)
{
    int q =1;
    int x;
    int t = first1->at;
    first2 = first1;
    first1 = first1->next;
    first2 -> next = first2;
    LinkedList *temp = first2;
    while(temp != NULL || first1 != NULL)
    {
        if(temp -> bt <= q)
        {
            t += q;
            cout << temp->pid <<" ";
            if(temp == first2)
            {
            	x = 0;
            	if(temp -> next == first2)
            	{
            		LinkedList *ptr = first2;
            		first2 = NULL;
            		delete ptr;
            		temp = NULL;
            		
                    if(first1 != NULL)
            		{
            			t = first1->at;
					}
				}
				else
				{
                    LinkedList *ptr = first2;
                    LinkedList *p = first2;
                    
                    while(p->next != first2)
                    {
                        p = p->next;
                    }
                    
                    first2 = first2 -> next;
                    p->next = first2;
                    temp = p->next;
                    delete ptr;
            	}
            }
            else
            {
            	x =1;
                LinkedList *ptr = temp;
                LinkedList *p = first2;
                
                while(p->next != temp)
                {
                    p = p->next;
                }

                p->next = temp->next;
                temp = p->next;
                delete ptr;
            }
            
        }
        else
        {
        	x =1;
            temp -> bt -= q;
            t += q;
            cout << temp->pid <<" ";
            temp = temp->next;
        }
        if(first1 != NULL && first1->at <=t)
        {
        	if(first2 == NULL)
        	{
        		first2 = first1;
        		first1 = first1->next;
        		first2->next = first2;
        		temp = first2;
			}
			else
			{
                LinkedList *ptr = first2;
                LinkedList *p = first2;
                
                while(ptr->next != first2)
                {
                    ptr = ptr->next;
                }
                
                ptr->next = first1;
                first1 = first1->next;
                ptr -> next -> next = first2;
                
                if(x == 1 && temp == p)
                {
                	temp = ptr->next;
    			}
		    }
        }
    }
}
int main() {
	int n;
	cin>>n;
	int *arr = new int[n]; 
	for(int i = 0 ;i < n ;i++)
	{
	    arr[i] = new int[3];
	    for(int j = 0 ;j < 3; j++)
	    {
	        cin>>arr[i][j];
	    }
	}
	LinkedList *a = create_List(arr,n,3);
	LinkedList *b = NULL;
	rr(a,b);
	return 0;
}
