#include <bits/stdc++.h> 
using namespace std; 
vector<string> ans;
void permute(string inp,string a, int l, int r) 
{ 
	if (l == r){
        if(inp<a){
		//cout<<a<<endl;
		ans.push_back(a); }}
	else
	{ 
		for (int i = l; i <= r; i++) 
		{ 

			swap(a[l], a[i]); 
			permute(inp,a, l+1, r);  
			swap(a[l], a[i]); 
		} 
	} 
} 

 
int main() 
{ 
	string inp;
    cin>>inp;
    string str=inp; 
	int n = str.size(); 
	permute(inp,str, 0, n-1); 
	sort(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x<<endl;
	}
	return 0; 
} 

