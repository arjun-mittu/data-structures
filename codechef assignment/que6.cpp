#include <iostream>
using namespace std;
class node
{
    public:
    int pid;
    int aot;
    int bt;
    node *next;
    node(int pid,int aot,int bt)
    {
        this -> pid = pid;
        this -> aot = aot;
        this -> bt = bt;
        this -> next = NULL;
    }
};
node* create_linked_list(int **a,int n,int m)
{
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = i+1 ; j < n ;j++)
        {
            if( a[i][1] > a[j][1])
            {
                int k;
                for(int g = 0 ; g < m ;g++){
                    k=a[i][g];
                    a[i][g]=a[j][g];
                    a[j][g]=k;
                }
            }
        }
    }

    node *start = NULL;
    node *end = NULL;
    
    for(int i = 0 ; i < n ;i++)
    {
        node *nL = new node(a[i][0],a[i][1],a[i][2]);
        if(start == NULL)
        {
            start = end = nL;
        }
        else
        {
            end -> next = nL;
            end = nL;
        }
    }
    return start;
}
void RR_sch(node *s1 , node *s2)
{
    int l =1;
    int g;
    int t = s1->aot;
    s2 = s1;
    s1 = s1->next;
    s2 -> next = s2;
    node *exp = s2;
    while(exp != NULL || s1 != NULL)
    {
        if(exp -> bt <= l)
        {
            t += l;
            printf("%d ",exp->pid);
            if(exp == s2)
            {
            	g = 0;
            	if(exp -> next == s2)
            	{
            		node *ptr = s2;
            		s2 = NULL;
            		delete ptr;
            		exp = NULL;
            		
                    if(s1 != NULL)
            		{
            			t = s1->aot;
					}
				}
				else
				{
                    node *ptr = s2;
                    node *pid = s2;
                    
                    while(pid->next != s2)
                    {
                        pid = pid->next;
                    }
                    
                    s2 = s2 -> next;
                    pid->next = s2;
                    exp = pid->next;
                    delete ptr;
            	}
            }
            else
            {
            	g =1;
                node *ptr = exp;
                node *pid = s2;
                
                while(pid->next != exp)
                {
                    pid = pid->next;
                }

                pid->next = exp->next;
                exp = pid->next;
                delete ptr;
            }
            
        }
        else
        {
        	g =1;
            exp -> bt -= l;
            t += l;
             printf("%d ",exp->pid);
            exp = exp->next;
        }
        if(s1 != NULL && s1->aot <=t)
        {
        	if(s2 == NULL)
        	{
        		s2 = s1;
        		s1 = s1->next;
        		s2->next = s2;
        		exp = s2;
			}
			else
			{
                node *ptr = s2;
                node *pid = s2;
                
                while(ptr->next != s2)
                {
                    ptr = ptr->next;
                }
                
                ptr->next = s1;
                s1 = s1->next;
                ptr -> next -> next = s2;
                
                if(g == 1 && exp == pid)
                {
                	exp = ptr->next;
    			}
		    }
        }
    }
}
int main() {
	int n;
	scanf("%d",&n);
	int **a = new int*[n]; 
	for(int i = 0 ;i < n ;i++)
	{
	    a[i] = new int[3];
	    for(int j = 0 ;j < 3; j++)
	    {
	        scanf("%d",&a[i][j]);
	    }
	}
	node *s1 = create_linked_list(a,n,3);
	node *s2 = NULL;
	RR_sch(s1,s2);
	return 0;
}
