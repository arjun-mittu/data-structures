#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<vector>
#include<set>
using namespace std;
#define ll long long int
int main(){
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        m[arr1[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    sort(arr2,arr2+n);
    cout<<"[";
    int checkf=0;
    for(int i=0;i<n;i++){
            if(m[arr2[i]]>0){
                 m[arr2[i]]-=1;
                 if(checkf==0){
                     cout<<arr2[i];
                     checkf=1;
                 }
                 else{
                     cout<<", "<<arr2[i];
                 }
             }
    }
    cout<<"]";
    /*vector<int> ans;
    for(int i = 0; i < n; i++){
        if(m[arr2[i]] > 0){
            m[arr2[i]]--;
            ans.push_back(arr2[i]);
        }
    }
    int f=0;
    cout<<"[";
    for(auto x: ans){
        cout<<", "<<x;
    }*/
    return 0;
}