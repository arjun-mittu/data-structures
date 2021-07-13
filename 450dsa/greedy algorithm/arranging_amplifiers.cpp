#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
    return a>b;
}
int32_t main(){
    int T;cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[n];
        int ones=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1) ones++;
        }
        sort(a,a+n,comp);
        for(int i=0;i<ones;i++) cout<<"1 ";
        if((n-ones)==2 && a[0]==3 && a[1]==2){
            cout<<"2 3"<<endl;
        }
        else{
            for(int i=0;i<(n-ones);i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}