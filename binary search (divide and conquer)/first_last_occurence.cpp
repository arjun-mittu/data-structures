#include<iostream>
using namespace std;
int first_occurence(int a[],int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int last_occurence(int a[],int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(a[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    int a[10]={1,2,3,4,4,5,6,7,8,9};
    int n=sizeof(a)/sizeof(int);
    int key=4;
    cout<<first_occurence(a,n,key)<<endl;
    cout<<last_occurence(a,n,key);
    return 1;
}