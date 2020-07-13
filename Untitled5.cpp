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
void rr(node *ll , node *scll)
{
    int l =1;
    int g;
    int t = ll->aot;
    scll = ll;
    ll = ll->next;
    scll -> next = scll;
    node *exp = scll;
    while(exp != NULL || ll != NULL)
    {
        if(exp -> bt <= l)
        {
            t += l;
            printf("%d ",exp->pid);
            if(exp == scll)
            {
            	g = 0;
            	if(exp -> next == scll)
            	{
            		node *ptr = scll;
            		scll = NULL;
            		delete ptr;
            		exp = NULL;
            		
                    if(ll != NULL)
            		{
            			t = ll->aot;
					}
				}
				else
				{
                    node *ptr = scll;
                    node *pid = scll;
                    
                    while(pid->next != scll)
                    {
                        pid = pid->next;
                    }
                    
                    scll = scll -> next;
                    pid->next = scll;
                    exp = pid->next;
                    delete ptr;
            	}
            }
            else
            {
            	g =1;
                node *ptr = exp;
                node *pid = scll;
                
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
        if(ll != NULL && ll->aot <=t)
        {
        	if(scll == NULL)
        	{
        		scll = ll;
        		ll = ll->next;
        		scll->next = scll;
        		exp = scll;
			}
			else
			{
                node *ptr = scll;
                node *pid = scll;
                
                while(ptr->next != scll)
                {
                    ptr = ptr->next;
                }
                
                ptr->next = ll;
                ll = ll->next;
                ptr -> next -> next = scll;
                
                if(g == 1 && exp == pid)
                {
                	exp = ptr->next;
    			}
		    }
        }
    }
}
main() {
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
	node *ll = create_linked_list(a,n,3);
	node *scll = NULL;
	rr(ll,scll);
}
