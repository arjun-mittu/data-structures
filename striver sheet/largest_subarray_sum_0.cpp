class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> m;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                ans=i+1;
            }
            else{
                if(m.find(sum)!=m.end()){
                    ans=max(ans,i-m[sum]);
                    
                }
                else{
                    m[sum]=i;
                }
            }
        }
        return ans;
    }
};