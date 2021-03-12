#include<bits/stdc++.h>
#define long long int ll
using namespace std;
int main(){
    int no,d;
    cin>>no;
    vector<int> A;
    for(int i=0;i<no;i++){
        cin>>d;
        A.push_back(d);
    }
    int dp[200][200];
    memset(dp,0,sizeof dp);
    int n=no-1;
    for(int i=1;i<n;i++){
        int r=0,c=i;
        while (c<n)
        {
            int val=INT_MAX;
            for(int pivot=r;pivot<c;pivot++){
                val=min(val,dp[r][pivot]+dp[pivot+1][c]+A[r]*A[pivot+1]*A[c+1]);
            }
            dp[r][c]=val;
            r++,c++;
        }
        
    }
    cout<<dp[0][n-1];
    return 0;
}