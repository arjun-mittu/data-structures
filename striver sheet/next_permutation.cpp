class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        while(j>0){
            if(nums[j]>nums[j-1]){
                break;
            }
            j--;
        }
        if(j==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int pivot_idx=j-1;
        int idx=n-1;
        while(nums[idx]<=nums[pivot_idx]) idx--;
        swap(nums[idx],nums[pivot_idx]);
        int rev=pivot_idx+1;
        reverse(nums.begin()+rev,nums.end());
    }
};