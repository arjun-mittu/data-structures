#include<iostream>
using namespace std;

int storeocc(int *a,int i,int n,int key,int *out,int j){
    if(i==n){
        return j;
    }
    if(a[i]==key){
        out[j]=i;
        return storeocc(a,i+1,n,key,out,j+1);
    }
    return storeocc(a,i+1,n,key,out,j);
}
void allocc(int *a,int i,int n,int key){
    if(i==n){
        return;
    }
    if(a[i]==key){
        cout<<i<<",";
    }
    allocc(a,i+1,n,key);
}
int lastocc(int *a,int n,int key){
    if(n==0){
        return -1;
    }
    int i=lastocc(a+1,n-1,key);
    if(i==-1){
        if(a[0]==key){
            return 0;
        }
        else{
            return -1;
        }
    }
    // i returned by sub problem not -1
    return i+1;
}
int ls(int *a, int n, int key){
    if(n==0){
        return -1;
    }

    if(a[0]==key){
        return 0;
    }
    int i=ls(a+1,n-1,key);
    if(i==-1){
        return -1;
    }
    return i+1;
}

// diff style it is like for loop
int lis(int *a,int i,int n,int key){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i;
    }
    return lis(a,i+1,n,key);
}
int main(){
    int arr[]={1,2,4,7,7};
    int key=7;
    int n=sizeof(arr)/sizeof(int);
    cout<<ls(arr,n,key)<<endl;
    cout<<lis(arr,0,n,key)<<endl;
    cout<<lastocc(arr,n,key)<<endl;
    allocc(arr,0,n,key);
    cout<<endl;
    int output[10];
    int cnt=storeocc(arr,0,n,key,output,0);
    for (int i = 0; i < cnt; i++)
    {
        cout<<output[i]<<" ";
    }
    
    return 0;
}