class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        /*int req=n/2;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr->second>req){
                return itr->first;
            }
        }
        return -1;*/
        int ma=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
                if(ma==nums[i]){
                    count++;
                }
                else{
                    count--;
                }
                if(count==0){
                    ma=nums[i];
                    count=1;
                }
        }
        return ma;
    }
};