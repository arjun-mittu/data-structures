#include<bits/stdc++.h>
using namespace std;
class Play_With_2D_Array
{
private:
	int **arr;
	int n; // for dimensions
	int i,j,k; // loop variables
	int t,min; //temporary variable
	int count;
	bool flag;
public:
	Play_With_2D_Array();
	void display();
	void swap(int & ,int &);
	void countSwaps();
	int getCount();
	~Play_With_2D_Array();
	
};
Play_With_2D_Array :: Play_With_2D_Array()
{
	// declaring array in heap
	cin>>n;
	if(n>0)
	{
		arr = new int *[n];
	}
	
	for (int i = 0; i <n; ++i)
	{
		arr[i] = new int [n];
	}

	// taking inputs from user
	
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
		}
	}
}
void  Play_With_2D_Array :: display()
{
	for ( i = 0; i < n; i++)
	{
		for (j = 0; j< n ; j++)
		{
			cout<<arr[i][j]<<" ";
		}
	}
	cout<<"\n";
}
void Play_With_2D_Array :: swap (int &x , int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void Play_With_2D_Array :: countSwaps()
{
	count = 0;
	for(i = 0; i < n; i++)
	{
	    for(j = 0; j < n; j++)
	    {
	        t = i;
	        min = arr[i][j];
	        for(k = i; k < n; k++)
	        {
	            if(arr[k][j] < min)
	            {
	                min = arr[k][j];
	                t = k;
	            }
	        }
	        if(t!=i){
	        	swap(arr[i][j] , arr[t][j]);
	        	count++;
	    	}
	    }
	    for(j = 0;j < n; j++)
	    {
	        t = i;
	        min = arr[j][i];
	        for(k = i; k < n; k++)
	        {
	            if(arr[j][k] < min)
	            {
	                min = arr[j][k];
	                t = k;
	            }
	        }
	        if(t!=i){
	        	swap(arr[j][i] , arr[j][t]);
	        	count++;
	    	}
	    }
	}
}
int Play_With_2D_Array ::  getCount()
{
	return count;
}
Play_With_2D_Array :: ~Play_With_2D_Array(){
 	for (int i = 0; i < n; ++i)
 	{
 		delete []arr[i];
 	}
 	delete []arr;
}
int main()
{
 	Play_With_2D_Array obj;
	int swaps;
	obj.countSwaps();
	swaps = obj.getCount();
	cout<<swaps<<endl;
	obj.display();
 	return 0;
}
