#include<iostream>
using namespace std;
bool is_sorted(int a[],int i,int n){
    if(n==0 || n==1){
        return true;
    }
    if(a[i]<=a[i+1] && is_sorted(a,i+1,n-1)){
        return true;
    }
    return false;
}
int main(){
    int n;
    int a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    if(is_sorted(a,i,n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}