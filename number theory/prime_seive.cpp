#include<iostream>
using namespace std;
void prime_seive(int *p){
    for(int i=3;i<=100;i+=2){
        p[i]=1;
    }
    for(int i=3;i<=100;i+=2){
        if(p[i]==1){
            for(int j=i*i;j<=100;j=j+i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;
}
int main(){
    int n;
    cin>>n;
    int p[100]={0};
    prime_seive(p);
    for(int i=0;i<=n;i++){
        if(p[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}