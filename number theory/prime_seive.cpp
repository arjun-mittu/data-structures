#include<iostream> 
using namespace std;
void prime_seive(int *p){
    //all odd as prime
    for (int i = 3; i <= 10000; i += 2)
    {
        p[i]=1;
    }
    //sieve 
    for (int i = 3; i <= 10000; i += 2)
    {
        //if the current number is not marked
        if(p[i]==1){
            //mark all the multiple of i as not prime
            for (int j = i * i; j <= 10000; j = j + i)
            {
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
    int p[10005] = {0};
    prime_seive(p);
    for(int i=0;i<=n;i++){
        if(p[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}