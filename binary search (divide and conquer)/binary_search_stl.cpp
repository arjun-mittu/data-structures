#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int a[10]={10,20,30,40,40,60,70,80,90,100};
    int n=sizeof(a)/sizeof(int);
    vector<int> ab{1,2,3,4,5,6,7,8,9,10};
    int key=40;
    bool present=binary_search(a,a+n,key);
    if(present){
        cout<<"yup";
    }else{
        cout<<"nope";
    }
    cout<<endl;
    auto it=lower_bound(a,a+n,45);
    auto iit=upper_bound(a,a+n,45);
    auto it1=lower_bound(ab.begin(),ab.end(),key);
    cout<<it1-ab.begin()<<endl;
    cout<<it-a<<endl;
    cout<<iit-a;
    return 1;
}