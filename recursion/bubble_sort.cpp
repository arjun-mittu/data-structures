#include<iostream>
using namespace std;
void buuble_sort_recursive(int a[],int j,int n){
    if(n==1){
        return;
    }
    if(j==n-1){
        //single pass of current array
        return buuble_sort_recursive(a,0,n-1);
    }
    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    buuble_sort_recursive(a,j+1,n);
    return;
}
void bubblesort(int a[],int n){
    if(n==1){
        return;
    }
    for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    bubblesort(a,n-1);
}
int main(){
    int a[]={1,5,3,4,2};
    int n=5;
    bubblesort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}