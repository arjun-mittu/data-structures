#include<iostream>
using namespace std;
int binary_search(int a[],int n,int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(int);
    int key=9;
    cout<<binary_search(a,n,key);
    return 1;
}