#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int target=0;
    vector <int> nums{1,0,-1,0,-2,2};
    vector<vector<int>> ans;
    int n=nums.size();
    if(n==0 || n<4){
        return {};
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
            for(int j=i+1;j<n-2;j++){
                if(j>1 && nums[j]==nums[j-1] && (j-i)>1){
                    continue;
                }
                    int left=j+1;
                    int right=n-1;
                    while(left<right){
                        int sum=nums[i]+nums[j]+nums[left]+nums[right];
                        if(sum==target){
                            ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                            while(left<right && nums[left]==nums[left+1]){
                                left++;
                            }
                            while(left<right && nums[right]==nums[right-1]){
                                right--;
                            }
                            left++;right--;
                        }
                        else if(sum>target){
                            right--;
                        }
                        else if(sum<target){
                            left++;
                        }
                    }
                
            }
        
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<4;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}