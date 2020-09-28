#include<iostream>
using namespace std;
void smallest_window(int a[],int n){
		
}
int main(){
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	smallest_window(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	return 0;
}
