class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n=nums.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target) return{i,j};
        //     }
        // }
        // return {};
        unordered_map<int,int> m;
        int rem;
        for(int i=0;i<nums.size();i++){
            rem=target-nums[i];
            if(m[rem]){
                return {m[rem]-1,i};
            }
            m[nums[i]]=i+1;
        }
        return {};
    }
};