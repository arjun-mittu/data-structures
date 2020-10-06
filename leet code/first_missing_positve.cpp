#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums{0,-1,3,1};
    int n=nums.size();
    int pnum=1;
    sort(nums.begin(),nums.end());
    int idx;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            idx=i;
            break;
        }
    }
    if(nums[idx]!=1){
        pnum=1;
    }
    else{
        int i=idx;
        while(nums[i]+1==nums[i+1] && i<n-2){
            i++;
        }
        i++;
        pnum=nums[i]+1;
    }
    cout<<pnum;
    return 0;
}