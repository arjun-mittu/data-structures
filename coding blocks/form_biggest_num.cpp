#include <bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
    while(a!=0){

    }
}
int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int n;
        cin >> n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,compare);
        for (int i = 0; i < n; i++)
        {
            cout<< arr[i];
        }
        cout<<endl;
        T--;
    }
    return 0;
}