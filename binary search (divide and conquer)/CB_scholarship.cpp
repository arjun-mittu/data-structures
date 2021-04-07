#include<iostream>
using namespace std;
bool is_possible(int n,int m,int x,int y,int ans){
    if((ans*x)<=m+(n-ans)*y){
        return true;
    }
    else{
        return false;
    }
}
int binary_search(int n,int m,int x,int y){
    int ans=0,s=0,e=n;
    int result;
    while(s<=e){
        int mid=(s+e)/2;
        ans=(m+(n-mid)*y)/x;
        if(ans>mid){
            s=mid+1;
            result=mid;
        }
        else if(ans<mid){
            e=mid-1;
        }
        else{
            return mid;
        }
    }
    return result;
}
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<binary_search(n,m,x,y);
    return 0;
}