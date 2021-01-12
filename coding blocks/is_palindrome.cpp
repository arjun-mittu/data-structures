#include<iostream>
using namespace std;
int check;
void palindrome(int *a,int l,int r){
    if(l>r){
        return;
    }
    if(a[l]==a[r]){
        check=1;
        palindrome(a,l+1,r-1);
    }
    else{
        check=0;
        return;
    }
}
int main(){
    int a[1000];
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    palindrome(a,0,n-1);
    if(check){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}