//method -1 using set
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> rs;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int s=j+1,e=n-1;
                int new_target=target-nums[i]-nums[j];
                while(s<e){
                    if(nums[s]+nums[e]==new_target){
                        
                        rs.insert({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;
                    }
                    else if(nums[s]+nums[e]>new_target){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x:rs){
            ans.push_back(x);
        }
        return ans;
    }
};


//method 2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<4) return ans;
        if(n==4){
            if(nums[0]+nums[1]+nums[2]+nums[3]==target) ans.push_back({nums[0],nums[1],nums[2],nums[3]});
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            while(i>0 && nums[i-1]==nums[i]){
                i++;
            }
            for(int j=i+1;j<n-2;j++){
                while(j>i && nums[j]==nums[j-1] && j-i>1){
                    j++;
                }
                int left=j+1;int right=n-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        left++ ; right--;
                    }
                    else if(sum<target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};