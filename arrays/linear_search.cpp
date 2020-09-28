#include<iostream>
using namespace std;
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9};
	int i=0;
	int key=7;
	for(i=0;i<10;i++)
	{
		if (key==a[i]){
			cout<<"element found at "<<i+1;
			break;
		}
	}
	return 1;
}
