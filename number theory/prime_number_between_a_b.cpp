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
    int p[100]={0};
    prime_seive(p);
    int csum[100]={0};
    for(int i=1;i<=100;i++){
        csum[i]=csum[i-1]+p[i];
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<csum[b]-csum[a-1]<<endl;
    }
    return 0;
}