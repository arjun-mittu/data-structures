#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[1000];
	int maxsum=0;
	int currsum=0;
	int left=-1;
	int right=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			currsum=0;
			for(int k=i;k<=j;k++){
				currsum+=a[k];
			}
			if(currsum>maxsum){
				maxsum=currsum;
				left=i;
				right=j;
			}
		}
	}
	cout<<maxsum<<endl;
	for(int k=left;k<=right;k++){
		cout<<a[k];
	}
	
	return 0;
	
}
