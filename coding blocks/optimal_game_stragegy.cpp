#include<iostream>
using namespace std;

int game(int *arr,int i,int j,int turn){
    if(i==j){
        return 0;
    }
    int max;
    int sump=0;
    if(turn==0){
    if(arr[i]>arr[j]){
        max=arr[i];
        i++;
    }
    else if(arr[i]<=arr[j]){
        max=arr[j];
        j--;
    } 
    turn=1;
     return sump+max+game(arr,i,j,turn);
    }    
    if(turn==1){
        if(arr[i]>arr[j]){
        i++;
    }
    else if(arr[i]<=arr[j]){
        j--;
    }
    max=0;
    turn=0;
    return sump+max+game(arr,i,j,turn);
    }
    

}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=game(arr,0,n-1,0);
    cout<<sum;
    return 0;
}