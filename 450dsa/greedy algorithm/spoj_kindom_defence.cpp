#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int w,h,n;
        cin>>w>>h>>n;
        vector<int> x_cord;
        vector<int> y_cord;
        x_cord.push_back(0);
        y_cord.push_back(0);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            x_cord.push_back(x);
            y_cord.push_back(y);
        }
        sort(x_cord.begin(),x_cord.end());
        sort(y_cord.begin(),y_cord.end());
        int max_x=INT_MIN,max_y=INT_MIN;
        for(int i=0;i<x_cord.size()-1;i++){
            int temp=x_cord[i+1]-x_cord[i]-1;
            max_x=max(max_x,temp);
            int temp_y=y_cord[i+1]-y_cord[i]-1;
            max_y=max(max_y,temp_y);
        }
        max_x=max(max_x,w-x_cord[x_cord.size()-1]);
        max_y=max(max_y,h-y_cord[y_cord.size()-1]);
        cout<<max_x*max_y<<endl;
    }
    return 0;
}