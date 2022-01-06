int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int t_xor=0;
    int ans=0;
    unordered_map<int,int> m;
    for(auto x:A){
        t_xor^=x;
        if(t_xor==B) ans++;
        if(m.find(t_xor^B)!=m.end()){
            ans+=m[t_xor^B];
        }
        m[t_xor]++;
    }
    return ans;
}