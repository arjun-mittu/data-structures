#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n;
    cin>>n;
    while(n!=0){
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        vector<pair<int,int>> buy;
        vector<pair<int,int>> sell;
        for(int i=0;i<n;i++){
            if(a[i]>0) buy.push_back({a[i],i});
            else sell.push_back({a[i],i});
        }
        int ans=0;
        int i=0;int j=0;
        while(i<buy.size() && j<sell.size()){
            int x=min(buy[i].first,-1*sell[j].first);
            buy[i].first-=x;
            sell[j].first+=x;
            int diff=abs(buy[i].second-sell[j].second);
            ans+=x*diff;
            if(buy[i].first==0) i++;
            if(sell[j].first==0) j++;
        }
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}