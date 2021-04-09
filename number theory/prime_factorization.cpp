#include <iostream>
#include<vector>
using namespace std;
void printFactorS(int n)
{
    vector<pair<int,int >> factors;
    int cnt;
    for (int i = 2;i<=n; i++){
        if(n%i==0){
            cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            factors.push_back({i,cnt});
        }
    }
    if(n!=1){
        //whatever is left is a prime number itself
        factors.push_back({n,1});
    }
    for(auto p:factors){
        cout<<p.first<<"^"<<p.second<<endl;
    }
    return;
}
vector<int> primeSieve(int *p,int n){
    p[0]=p[1]=0;
    p[2]=1;
    for(int i=3;i<=n;i+=2){
        p[i]=1;
    }
    for(int i=3;i<=n;i+=2){
        if(p[i]){
            for(int j=i*i;j<=n;j+=2*i){
                p[j]=0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<=n;i++){
        if(p[i]==1){
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> factorize_seive(int m,vector<int> &primes){
    vector<int> factors;
    factors.clear();
    int i=0;
    int p=primes[0];
    while(p*p<=m){
        if(m%p==0){
            factors.push_back(p);
            while(m%p==0){
                m=m/p;
            }
        }
        //go to the next position
        i++;
        p=primes[i];
    }
    if(m!=1){
        factors.push_back(m);
    }
    return factors;
}
int no_of_divisors(int m, vector<int> &primes)
{
    int i = 0;
    int p = primes[0];
    int ans=1;
    while (p * p <= m)
    {
        if (m % p == 0)
        {
            int cnt=0;
            while (m % p == 0)
            {
                cnt++;
                m = m / p;
            }
            ans=ans*(cnt+1);
        }
        //go to the next position
        i++;
        p = primes[i];
    }
    if(m!=1){
        ans=ans*2;
    }
    return ans;
}
int main()
{
    //int n;
    //cin >> n;
    //printFactorS(n);
    int N=10000;
    int p[N]={0};
    vector<int> primes = primeSieve(p, 10000);
    int t;
    cin>>t;
    while(t--){
        int no;
        cin>>no;
        vector<int> factors=factorize_seive(no,primes);
        for(auto f:factors){
            cout<<f<<" "<<endl;
        }
        cout<<no_of_divisors(no,primes)<<endl;
    }
    return 0;
}