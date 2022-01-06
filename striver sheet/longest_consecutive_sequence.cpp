class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        map<int,bool> m;
        for(auto x:nums){
            m[x]=true;
        }
        int ans=0;
        int temp=0;
        bool first_itr=true;
        int prev;
        for(auto x:m){
            if(first_itr){
                prev=x.first;
                temp++;
                ans=max(ans,temp);
                first_itr=false;
            }
            else{
                if(x.first-prev==1){
                    temp++;
                }
                else temp=1;
                ans=max(ans,temp);
                prev=x.first;
            }
        }
        return ans;
    }
};