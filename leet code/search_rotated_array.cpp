#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums{4,5,6,7,0,1,2};
    int s=0;
    int e=nums.size()-1;
    int target=0;
    int pos;
    while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]==target){
            pos=mid;
        }
        else if(nums[s]<=nums[mid]){
            if(target>=nums[s] && target<=nums[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else{
            if(target>=nums[mid] && target<=nums[e]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    cout<<pos;
    return 1;
}