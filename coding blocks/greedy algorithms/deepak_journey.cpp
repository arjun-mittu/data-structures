#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T--){
        long long int n;
        cin>>n;
        long long int C[n];
        long long int L[n];
        for(int i=0;i<n;i++){
            cin>>C[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> L[i];
        }
        long long int cost = 0;
        long long int mincost = C[0];
        cost+=mincost*L[0];
        for(int i=1;i<n;i++){
            int cur=C[i];
            mincost=min(mincost,cur);
            cost+=mincost*L[i];
        }
        cout<<cost<<endl;
    }
    return 0;
}