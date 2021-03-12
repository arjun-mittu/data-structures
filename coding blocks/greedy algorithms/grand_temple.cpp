#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *x=new int[n];
    int *y=new int[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    int dx=INT_MIN;
    int dy=INT_MIN;
    for(int i=1;i<n;i++){
        dx=max(dx,x[i]-x[i-1]-1);
        dy=max(dy,y[i]-y[i-1]-1);
    }
    cout<<dx*dy;
    return 0;
}