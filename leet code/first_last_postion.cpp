#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums{5,7,7,8,8,8,10};
    int n=nums.size();
    int target=6;
    vector<int> ans{-1,-1};
    int first=-1;
    int last=-1;
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
           if(first<0){
           first=i;}
           count++;
        }
       
    }
    if(first>=0)
    {ans[0]=first;
    ans[1]=first+count-1;}
    cout<<count<<endl;
    cout<<ans[0]<<ans[1];
    return 0;
}