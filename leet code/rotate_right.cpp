#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> reverse(vector<int> a,int start,int end){
    while(start<end){
        a[start]=a[start]+a[end];
        a[end]=a[start]-a[end];
        a[start]=a[start]-a[end];
        start++;
        end--;
        
    }
    return a;
}
int main(){
    vector<int> a{1,2,3,4,5};
    int k=2;
    k=k%a.size();
    a=reverse(a,0,a.size()-1);
    a=reverse(a,0,k-1);
    a=reverse(a,k,a.size()-1);
    for(auto x:a){
        cout<<x<<" ";
    }
    return 1;
}