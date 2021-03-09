#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int > m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]=0;
    }
    int max_f=INT_MIN;
    int key;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        max_f=max(max_f,m[arr[i]]);
        if(max_f==m[arr[i]]){
            key=arr[i];
        }
    }
    cout<<key;
    return 0;
}