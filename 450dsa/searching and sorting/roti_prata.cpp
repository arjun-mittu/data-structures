#include<bits/stdc++.h>
#define int long long int
using namespace std;
bool isvalid(int *rank,int par,int cook,int ans){
    int time=0;
    int parata=0;
    for(int i=0;i<cook;i++){
        time=rank[i];
        int j=2;
        while(time<=ans){
            parata++;
            time=time+(rank[i]*j);
            j++;
        }
        if(parata>=par) return 1;
    }
    return 0;

}
int32_t main(){
    int T;cin>>T;
    while(T--){
        int par,cook;
        cin>>par>>cook;
        int rank[cook];
        for(int i=0;i<cook;i++){
            cin>>rank[i]; 
        }
        int s=0;
        int e=1e8;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            if(isvalid(rank,par,cook,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        cout<<ans<<endl;
    }



    return 0;
}