#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> ans;
    
    vector<int> nums{-1,0,1,2,-1,-4};
    int sum;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(nums[k]);
                    ans.push_back(a);
                   
                }
            }
        }
    }
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}