#include <iostream>
#include <algorithm>
using namespace std;
void counting_sort(int *a, int n)
{
    //asuming numbers>0
    int max_val=*max_element(a,a+n);
    int min_val=*min_element(a,a+n);
    int range=max_val-min_val+1;
    int farr[range]={0};
    for(int i=0;i<n;i++){
        int idx=a[i]-min_val;
        farr[idx]++;
    }
    for(int i=1;range;i++){
        farr[i]=farr[i]+farr[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int val=a[i];
        int pos=farr[val-min_val];
        int idx=pos-1;
        a[idx]=val;
        farr[val-min_val]--;
    }
}
int main()
{
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr) / sizeof(int);

    counting_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}