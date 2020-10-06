#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int>nums{-1,2,1,-4};
    int target=1;
    int n=nums.size();
    int sum;
    int diff=INT_MAX;
    int tempdiff;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
            sum=nums[i]+nums[left]+nums[right];
            tempdiff=sum-target;
            if(abs(tempdiff)<abs(diff)){
                diff=tempdiff;
            }
            if(sum<target){
                left++;
            }
            if(sum>target){
                right--;
            }
            if(sum==target){
                left++;right--;
            }
        }
    }
    int csum;
    if(diff<0){
        csum=target+abs(diff);
    }
    else{
        csum=target+diff;
    }
    cout<<csum;
    return 0;
}