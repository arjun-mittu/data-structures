#include<stdio.h>
#include<stdlib.h>
typedef struct LL
{
	int pid;
    int arrivalTime;
    int burstTime;
    LL *link;
	struct LL* link;
}LL;
LL *create_list(int n){
	int i=0;
	LL* head=NULL;
	LL* temp=NULL;
	LL* p=NULL;
	for(i=0;i<n;i++){
		temp=(LL*)malloc(sizeof(LL));
		scanf("%d",&(temp->pid));
		scanf("%d",&(temp->arrivalTime));
		scanf("%d",&(temp->burstTime));
		temp->link=NULL;
		if(head==NULL){
			head=temp;
		}
		else{
			p=head;
			while(p->link!=NULL){
				p=p->link;
			}
			p->link=temp;
		}
	}
	p=p->link;
	/*p->link=head;*/
	return head;
}
void rr(LL *first1,LL *first2){
	int q =1;
    int x;
    int t = first1->arrivalTime;
    first2 = first1;
    first1 = first1->link;
    first2 -> link = first2;
    LL *temp = first2;
    while(temp != NULL || first1 != NULL)
    {
        if(temp -> burstTime <= q)
        {
            t += q;
            cout << temp->pid <<" ";
            if(temp == first2)
            {
            	x = 0;
            	if(temp -> link == first2)
            	{
            		LL *ptr = first2;
            		first2 = NULL;
            		free(ptr);
            		temp = NULL;
            		
                    if(first1 != NULL)
            		{
            			t = first1->arrivalTime;
					}
				}
				else
				{
                    LL *ptr = first2;
                    LL *p = first2;
                    
                    while(p->link != first2)
                    {
                        p = p->link;
                    }
                    
                    first2 = first2 -> link;
                    p->link = first2;
                    temp = p->link;
                    free(ptr);
            	}
            }
            else
            {
            	x =1;
                LL *ptr = temp;
                LL *p = first2;
                
                while(p->link != temp)
                {
                    p = p->link;
                }

                p->link = temp->link;
                temp = p->link;
                free(ptr);
            }
            
        }
        else
        {
        	x =1;
            temp -> burstTime -= q;
            t += q;
            cout << temp->pid <<" ";
            temp = temp->link;
        }
        if(first1 != NULL && first1->arrivalTime <=t)
        {
        	if(first2 == NULL)
        	{
        		first2 = first1;
        		first1 = first1->link;
        		first2->link = first2;
        		temp = first2;
			}
			else
			{
                LL *ptr = first2;
                LL *p = first2;
                
                while(ptr->link != first2)
                {
                    ptr = ptr->link;
                }
                
                ptr->link = first1;
                first1 = first1->link;
                ptr -> link -> link = first2;
                
                if(x == 1 && temp == p)
                {
                	temp = ptr->link;
    			}
		    }
        }
    }
}
int main(){
	LL* head=NULL;
	int n,m;
	scanf("%d",&n);
	head=create_list(n);
	LL* head2=NULL;
	rr(head,head2);
}
