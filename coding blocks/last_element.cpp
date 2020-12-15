#include<iostream>
using namespace std;

int lastocc(int *a,int n,int key){
    if(n==0){
        return -1;
    }
    int i=lastocc(a+1,n-1,key );
    if(i==-1){
        if(a[0]==key){
            return 0;
        }
        else{
            return -1;
        }
    }
    return i+1;
}
int main(){
    int n;
    int a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<lastocc(a,n,key);
}