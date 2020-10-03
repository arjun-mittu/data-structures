#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> height{1,8,6,2,5,4,8,3,7};
    int max=0;
    int n=height.size();
    int width;
    int start=0;
    int end=n-1;
    int val;
    while(start<end){
        width=end-start;
        int val=min(height[start],height[end]);
        int area=width*val;
        if(max<area){
            max=area;
        }
        if(height[start]<height[end]){
            start++;
        }
        else{
            end--;
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val=min(height[i],height[j]);
            width=j-i;
            int area=width*val;
            if(max<area){
            max=area;
            }
        }
    }*/
    cout<<max;
    return 1;

}