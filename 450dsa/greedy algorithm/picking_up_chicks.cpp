#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int T;
    cin>>T;
    while(T--){
        int n,k,barn,time;
        cin>>n>>k>>barn>>time;
        int x[n],v[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int ans=0;
        int cnt=0;
        vector<pair<int,int>> both;
        for(int i=0;i<n;i++){
            both.push_back({x[i],v[i]});
        }
        while(time!=0){
            for(int i=0;i<n;i++){
                both[i].first+=both[i].second;
            }
            for(int i=1;i<n;i++){
                if(both[i-1].first>=both[i].first && both[i-1].second>both[i].second){
                    swap(both[i-1],both[i]);
                    ans++; 
                }
            }
            for(int i=0;i<n;i++){
                if(both[i].first>=barn){
                    cnt++;
                    n--;
                }
            }
            time--;
        }
        if(cnt>=k){
            cout<<ans<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}