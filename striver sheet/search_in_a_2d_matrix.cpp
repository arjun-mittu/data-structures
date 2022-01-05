class Solution {
public:
    bool binary_search(vector<int> &nums,int target){
        int s=0;
        int e=nums.size()-1;
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            if(nums[mid]==target) return true;
            else if(target<nums[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==1) return binary_search(matrix[0],target);
        int s=0;
        int e=m-1;
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            if(matrix[mid][0]==target || matrix[mid][n-1]==target) return true;
            else if(matrix[mid][0]<target and matrix[mid][n-1]>target) return binary_search(matrix[mid],target);
            else if(matrix[mid][0]>target){
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return false;
    }
};