class Solution {
public:
    bool checkall(vector<int> &nums){
        for(auto x:nums){
            if(x>0){
                return false;
            }
        }
        return true;
    }
    int maxSubArray(vector<int>& nums) {
        if(checkall(nums)){
            int ans=INT_MIN;
            for(auto x:nums){
                ans=max(x,ans);
            }
            return ans;
        }
        else{
            int ans=0;
            int temp=0;
            for(auto x:nums){
                temp+=x;
                ans=max(temp,ans);
                if(temp<0) temp=0;
            }
            return ans;
        }
    }
};