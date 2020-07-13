#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[]={1,2,3,4,5,6,7,9,10};
	int s=16;
	int i=0;
	int j=sizeof(a)/sizeof(int)-1;
	while(i<j){
		int currsum=a[i]+a[j];
		if(currsum>s){
			j--;
		}
		else if(currsum<s){
			i++;
		}
		else if(currsum==s){
			cout<<a[i]<<" and "<<a[j]<<endl;
			i++;
			j--;
		}
	}
	return 0;
	
}
