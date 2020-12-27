#include<iostream>
using namespace std;
int place_tile(int n,int m){
    if(n<1){
        return 0;
    }
    if(n<m){
        return 1;
    }
    if(n==m){
        return 2;
    }
    return place_tile(n-1,m)+place_tile(n-m,m);
}
int main(){
    int t;
    cin>>t;
    int case_=0;
    while(case_<t){
        int n,m;
        cin>>n>>m;
        int ways=place_tile(n,m);
        cout<<ways<<endl;
        case_++;
    }
}