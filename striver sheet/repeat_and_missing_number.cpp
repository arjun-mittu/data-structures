vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long n=A.size();
    long expected_sum=(n*(n+1))/2;
    long expected_sq_sum=(n*(n+1)*((2*n)+1))/6;
    for(long i=0;i<n;i++){
        expected_sum-=A[i];
        expected_sq_sum-=A[i]*A[i];
    }
    
    long missing=(expected_sum+(expected_sq_sum/expected_sum))/2;
    long repeat=missing-expected_sum;
    vector<int> ans;
    ans.push_back((int)repeat);
    ans.push_back((int)missing);
    return ans;
}
