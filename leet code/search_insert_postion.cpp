#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find_val(vector<int> nums,int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    vector <int> nums{1,3,5,6};
    int target=7;
    int n=nums.size();
    int pos=find_val(nums,target);
    if(pos<0){
        int i=0;
        while(nums[i]<target){
            if(i==nums.size()){
                break;
            }
            else{i++;}
        }
        pos=i;
    }
    cout<<pos;
    return 0;
}