#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool comp(int a,int b){
    return a>b;
}
int32_t main(){
    int T;
    cin>>T;
    while(T--){
        int m,n;
        cin>>m>>n;
        m--;n--;
        int x[m],y[n];
        for(int i=0;i<m;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        sort(x,x+m,comp);
        sort(y,y+n,comp);
        int ans=0;
        int vert=1,horz=1;
        int i=0,j=0;
        while(i<m && j<n){
            if(x[i]>y[j]){
                ans+=x[i]*vert;
                i++;
                horz++;
            }
            else{
                ans += y[j] * horz;
                j++;
                vert++;
            }
        }
        int total=0;
        while(i<m){
            total+=x[i++];
        }
        ans+=total*vert;
        total=0;
        while(j<n) total+=y[j++];
        ans+=total*horz;
        cout<<ans<<endl;
    }
    return 0;
}