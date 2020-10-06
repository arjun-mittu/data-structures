#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector <int> reverse(vector<int> a,int start,int end){
    while(start<end){
        a[start]=a[start]+a[end];
        a[end]=a[start]-a[end];
        a[start]=a[start]-a[end];
        start++;
        end--;
        
    }
    return a;
}
int main(){
    vector<int> nums{3,2,1};
    int n=nums.size();
    if(n>1){
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i>-0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        nums=reverse(nums,i+1,n-1);
    }
    for(auto x:nums){
        cout<<x;
    }
    return 0;
}