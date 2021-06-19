#include<bits/stdc++.h>
using namespace std;
#define long long int
int32_t main(){
    int n;
    cin>>n;
    int keys[n];
    for(int i=0;i<n;i++){
        cin>>keys[i];
    }
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }
    int psa[n];
    psa[0]=freq[0];
    for(int i=1;i<n;i++){
        psa[i]=psa[i-1]+freq[i];
    }
    int dp[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                dp[i][j]=freq[i];
            }
            else if(g==1){
                int f1=freq[i];
                int f2=freq[j];
                dp[i][j]=min(f1+2*f2,2*f1+f2);
            }
            else{
                int m=INT_MAX;
                //int fs=0;
                int fs=psa[j]-(i==0?0:psa[i-1]);
                /*for(int x=i;x<=j;x++){
                    fs+=freq[x];
                }*/
                for(int k=i;k<=j;k++){
                    int left=k==i?0:dp[i][k-1];
                    int right = k == j ? 0 : dp[k + 1][j];
                    m=min(m,left+right+fs);
                }
                dp[i][j]=m;
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}