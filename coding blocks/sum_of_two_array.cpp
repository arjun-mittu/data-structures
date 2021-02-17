#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a1[1000];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    int m;
    cin>>m;
    int a2[1000];
    for (int i = 0; i < n; i++)
    {
        cin>>a2[i];
    }
    int carry=0;
    int greater=max(n,m);
    int lower=min(n,m);
    //cout<<greater;
    int sum[1000];
    int i=greater-1;
    int j=lower-1;
    while(i>=0){
        if(j>=0){
            int sum_l;
            if(n>m){
                sum_l=a1[i]+a2[j]+carry;
            }
            else{
                sum_l = a1[j] + a2[i] + carry;
            }
            if(sum_l>=10){
                carry=1;
            }
            else{
                carry=0;
            }
            sum[i] = sum_l % 10;
            j--;i--;
        }
        else{
        int sum_h;
        if (n > m)
        {
            sum_h = a1[i]  + carry;
        }
        else
        {
            sum_h = a2[i] + carry;
        }
        if (sum_h >= 10)
        {
            carry = 1;

        }
        else{
            carry=0;
        }
        sum[i] = sum_h % 10;
        i--;
        }
    }
    for(int s=0;s<greater;s++){
        cout<<sum[s]<<" ";
    }
    return 0;
}