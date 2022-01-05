class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int ele1=-1;
        int ele2=-1;
        for(auto el:nums){
            if(el==ele1) cnt1++;
            else if(el==ele2) cnt2++;
            else if(cnt1==0){
                ele1=el;
                cnt1=1;
            }else if(cnt2==0){
                ele2=el;
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        int n=nums.size();
        
        int count1=0,count2=0;
        for(auto x:nums){
            if(x==ele1) count1++;
            else if(x==ele2) count2++;
        }
        
        if(count1>n/3) ans.push_back(ele1);
        if(count2>n/3) ans.push_back(ele2);
        return ans;
    }
};