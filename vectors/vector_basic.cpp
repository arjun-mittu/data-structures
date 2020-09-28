#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> a;
	vector<int> b(5,10); // vector with 5 int and values
	vector<int> c(b.begin(),b.end());
	vector<int> d{1,2,3,10};
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	for(auto it=b.begin();it!=b.end();it++){
		cout<<(*it)<<",";
	}
	cout<<endl;
	for(int x:d){
		cout<<x<<",";
	}
	vector<int> v;
	int n=5;
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		v.push_back(number); // add at end
	}
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl; //size of underlying array
	cout<<v.max_size()<<endl; //maximum number of elements array can hold in worst case
	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl; //size of underlying array
	cout<<d.max_size()<<endl; //maximum number of elements array can hold
	return 0;
}
