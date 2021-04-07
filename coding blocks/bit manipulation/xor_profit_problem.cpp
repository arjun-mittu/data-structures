#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int ans=INT_MIN;
    for(int i=a;i<=b;i++){
        for(int j=i;j<=b;j++){
            int temp=i^j;
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}