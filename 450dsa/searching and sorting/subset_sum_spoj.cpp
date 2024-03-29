#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(int *a,int st,int end,vector<int>&v1){
    int s=0;
    int n=end-st+1;
    for(int i=0;i<(1<<n);i++){
        s=0;
        int j=st;
        int x=i;
        while(x){
            int l=x&1;
            if(l) s+=a[j];
            j++;
            x=x>>1;
        }
        v1.push_back(s);
    }
}
int32_t main(){
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v1,v2;
    solve(arr,0,(n/2)-1,v1);
    solve(arr,n/2,n-1,v2);
    sort(v2.begin(),v2.end());
    int ans=0;
    for(int i=0;i<v1.size();i++){
        int low=lower_bound(v2.begin(),v2.end(),a-v1[i])-v2.begin();
        int high=upper_bound(v2.begin(),v2.end(),b-v1[i])-v2.begin();
        ans+=(high-low);
    }
    cout<<ans<<endl;
    return 0;
}