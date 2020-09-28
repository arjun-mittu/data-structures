#include<iostream>
using namespace std;

void waveprint(int a[][10],int m,int n){
	for (int col=0;col<m;col++){
        if(col%2==0){
            for(int row=0;row<n;row++){
                cout<<a[row][col]<<" ";}
            }
        
        else{
            for(int row=n-1;row>=0;row--){
                cout<<a[row][col]<<' ';
            }
        }
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
	waveprint(a,m,n);
	return 0;
}
