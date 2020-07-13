#include <iostream>
using namespace std;
class LL
{
    public:
    int pid;
    int arrivalTime;
    int burstTime;
    LL *link;
    LL(int pid,int arrivalTime,int burstTime)
    {
        this -> pid = pid;
        this -> arrivalTime = arrivalTime;
        this -> burstTime = burstTime;
        this -> link = NULL;
    }
};
LL* create_LL(int **arr,int n,int m)
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

    LL *first = NULL;
    LL *last = NULL;
    
    for(int i = 0 ; i < n ;i++)
    {
        LL *newLL = new LL(arr[i][0],arr[i][1],arr[i][2]);
        if(first == NULL)
        {
            first = last = newLL;
        }
        else
        {
            last -> link = newLL;
            last = newLL;
        }
    }
    return first;
}
void RR_Scheduling(LL *first1 , LL *first2)
{
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
            		delete ptr;
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
                    delete ptr;
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
                delete ptr;
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
int main() {
	int n;
	cin>>n;
	int **arr = new int*[n]; 
	for(int i = 0 ;i < n ;i++)
	{
	    arr[i] = new int[3];
	    for(int j = 0 ;j < 3; j++)
	    {
	        cin>>arr[i][j];
	    }
	}
	LL *first1 = create_LL(arr,n,3);
	LL *first2 = NULL;
	RR_Scheduling(first1,first2);
	for(int i = 0; i < n; i++)
	{
		delete [] arr[i];
	}
	delete arr;
	return 0;
}