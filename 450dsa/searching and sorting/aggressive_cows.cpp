#include <bits/stdc++.h>
using namespace std;
bool check(int *stalls,int n,int c,int dist){
    int count=1;
    int temp=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-temp>=dist){
            temp=stalls[i];
            count++;
            if (count == c)
            {
                return true;
            }
        }       
    }
    return false;
}

int main()
{
    int T;cin>>T;
    while(T--){
        int n,c;
        cin>>n>>c;
        int stalls[n];
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls,stalls+n);
        int s=0;
        int e=stalls[n-1]-stalls[0];
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            bool rakh=check(stalls,n,c,mid);
            if(rakh){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}