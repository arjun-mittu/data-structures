#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{1,2,3,3,4};
    int prev=0;
    for(int curr=1; curr<a.size();curr++){
        if(a[prev]!=a[curr]){
            prev++;
            a[prev]=a[curr];
        }
    }
    cout<<prev+1;
    return 1;
}