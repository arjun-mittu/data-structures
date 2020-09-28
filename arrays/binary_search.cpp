#include<iostream>
using namespace std;
void binary(int a[],int n,int l,int r,int key){
	int mid=(l+r)/2;
	if(key==a[mid]){
		cout<<"element found at"<<mid+1;
	}
	if( key<a[mid]){
		l=0;
		r=mid;
		binary(a,9,l,r,key);
	}
	if(key>a[mid]){
		l=mid;
		binary(a,9,l,r,key);
	}
}
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9};
	int i=0;
	int key=7;
	int l=0;
	int r=9;
	binary(a,9,l,r,key);
}
