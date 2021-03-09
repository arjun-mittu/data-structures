#include <iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main()
{   
    int n;
    cin>>n;
    unordered_set<int> s;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    int j = 0;
    for(int i=0;i<n;i++){
        while (j < n && s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
        ans+=((j-i+0)*(j-i+1))/2;
        s.erase(arr[i]);
    }
    cout<<ans;
    return 0;
}