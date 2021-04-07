#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    int full_xor = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        full_xor=full_xor^a[i];
    }
    int temp_xor=full_xor;
    int idx=0;
    while(temp_xor>0){
        if(temp_xor&1){
            //idx++;
            break;
        }
        idx++;
        temp_xor>>1;
    }
    int mask=(1<<idx);
    int no1=0,no2;
    for(int i=0;i<n;i++){
        if((a[i]&mask)>0){
            no1=no1^a[i];
        }
    }
    no2=full_xor^no1;
    if(no1<=no2){
        cout << no1 << " "<< no2<<endl;
    }
    else{
        cout<<no2<<" "<<no1<<endl;
    }
    return 0;
}