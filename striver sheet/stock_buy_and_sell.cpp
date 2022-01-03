class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mm=INT_MAX,profit=0;
        for(auto x:prices){
            mm=min(mm,x);
            profit=max(profit,x-mm);
        }
        return profit;
    }
};