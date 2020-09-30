#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector <int> nums{1,3,5,6};
    int target=5;
    int n=nums.size();
    int i=0;
    while(nums[i]<target){
        if(i==nums.size()){
            break;
        }
            else{i++;}
        }
    
    cout<<i;
    return 0;
}