#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[4]={0,3,1,2};
    int n=4;
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                flag=1;
            }
        }
        if(flag==1){
            cout<<a[i];
        }
    }
    return 0;
}