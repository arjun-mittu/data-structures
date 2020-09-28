#include<iostream>
using namespace std;
void left_rotate(int a[],int n){
	int temp=a[0];
	int i;
	for(i=0;i<n;i++){
		a[i]=a[i+1];
	}
	a[n-1]=temp;
}
int main(){
	int n,d;
    cin>>n;
    cin>>d;
    int a[n]={0};
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=d;i++){
    left_rotate(a,n);}
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
