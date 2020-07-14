#include<iostream>
using namespace std;

void spiralprint(int a[][10],int m,int n){
	int sr=0;
	int sc=0;
	int er=n-1;
	int ec=m-1;
	while(sr<=er and sc<=ec){
		for(int i=sc;i<=ec;i++){
			cout<<a[sr][i]<<" ";
		}
		sr++;
		for(int i=sr;i<=er;i++){
			cout<<a[i][ec]<<" ";
		}
		ec--;
		if(er>sr){
		for(int i=ec;i>=sc;i--){
			cout<<a[er][i]<<" ";
		}
		er--;}
		if(ec>sc){
		for(int i=er;i>=sr;i--){
			cout<<a[i][sc]<<" ";
		}sc++;}
	}
}
int main(){
	int a[10][10]={0};
	int n,m;
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	spiralprint(a,m,n);
	return 0;
}
