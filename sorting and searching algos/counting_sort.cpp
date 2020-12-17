#include<iostream>
#include<algorithm>
using namespace std;
void counting_sort(int *a,int n){
    //asuming numbers>0
    int largest=-1;
    for(int i=0;i<n;i++){
        largest=max(largest,a[i]);
    }
    int *freq=new int[largest+1]{0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }

    //back to array a from freq array
    int j=0;
    for(int i=0;i<=largest;i++){
        while(freq[i]>0){
            a[j]=i;
            freq[i]--;
            j++;
        }
    }

}
int main(){
    int arr[]={88,97,10,12,15,1,5,6,12,5,8};
    int n=sizeof(arr)/sizeof(int);
    counting_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}