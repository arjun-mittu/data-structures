#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long int n,l,r;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n>1){
            sort(a,a+n);
            long long int min_ans=0;
            long long int max_ans = 0;
            for(int i=0;i<n;i=i+2){
                min_ans+=abs(a[i]-a[i+1]);
            }
            l=0;r=n-1;
            while(l<r){
                max_ans+=abs(a[r]-a[l]);
                l++;r--;
            }
            cout<<min_ans<<" "<<max_ans<<endl;
        }
        else{
            cout<<a[0]<<" "<<a[0]<<endl;
        }
    }
    return 0;
}