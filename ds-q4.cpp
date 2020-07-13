#include<iostream>
using namespace std;
int main()
{
	int x,y,z,i,j,k,num;
	//no=0,iter=0;
	cin>>x>>y>>z>>num;
	int a[x][y][z];
	
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			for(k=0;k<z;k++)
			{
				cin>>a[i][j][k];
			}
		}
	}
	
	
	
	int ipos,fpos,mid;
	while(i<x)
	{
		if(num>a[i][0][0] && num<a[i][y-1][z-1])
		{
			cout<<a[i][0][0]<<" "<<a[i][y-1][z-1]<<endl;
			ipos=0;
			fpos=y*z;
			while(ipos<=fpos)
			{
				mid=(ipos+(fpos-ipos)/2);
				row=mid/z;
				col=mid%z;
				value=a[row][col];
				if(a[mid]==val)
				{
					cout<<"element found\n";
					flag++;
					break;
				}
				else if(val>num)
				{
					fpos=mid-1;
				}
				else
				{
					ipos=mid+1;
				}
			}
		}
		
		i++;
	}
	if(flag==0)
	{
		cout<<"element not found\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	/// via linear search
	
	// 1 dimension
	for(i=0;i<x;i++)
	{
		if(num>=a[i][0][0] && num<=a[i][y-1][z-1])
		{
			cout<<a[i][0][0]<<" "<<a[i][y-1][z-1]<<endl;
			no++; //1
			for(j=0;j<y;j++) // 2 dimension
			{
				
				if(num>=a[i][j][0] && num<=a[i][j][z-1])
				{
					cout<<a[i][j][0]<<" "<<a[i][j][z-1]<<endl;
					no++; //2
					for(k=0;k<z;k++)  // 3 dimension
					{
						iter++;
						if(a[i][j][k]==num)
						{
							cout<<i<<" "<<j<<" "<<k<<endl;
							no++; //3
							break;
						}
					}
				}
				iter++;
				if(no==3)
				break;
				
			}  // end of 2 dim for
		} //end of 1 dim for
		
		if(no==3)
		{
			break;
		}
		else if(i==x-1 && no!=3)  // 
		{
			break;
		}
		else{
			iter++;
		}
		
	}
	if(no==0 || no==1 || no==2)
		{
			cout<<0<<endl;
		}
	cout<<iter<<endl;	
	
}

