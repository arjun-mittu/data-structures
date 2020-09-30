#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums{3,2,2,3};
    int val=3;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==val){
            swap(nums[i],nums[n-1]);
            n--;
            i--;
        }
    }
    /*
    for (auto i = nums.begin(); i != nums.end(); ++i) { 
        if (*i==val) { 
            nums.erase(i); 
            i--; 
        } 
    } */
    cout<<n;
    return 0;
}