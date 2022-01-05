class Solution {
public:
    double power_optimised(double x,long long n){
        double ans=1;
        while(n>0){
            long long int last_bit=(n&1);
            if(last_bit){
                ans=ans*x;
            }
            x=x*x;
            n=n>>1;
        }
        return ans;
    }
    double myPow(double x, long long int n) {
        if(x==1) return 1;
        if(n>0) return power_optimised(x,n);
        if(n<0) {
            return 1/power_optimised(x,-n);
        }
        return 1;
    }
};