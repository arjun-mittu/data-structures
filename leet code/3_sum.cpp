#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> ans;
    
    vector<int> nums{-1,0,1,2,-1,-4};
    int sum;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n-2;i++){
        if(i==0 || nums[i]!=nums[i-1]){
            int j=i+1;int k=n-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}