#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}
int main()
{
    int n,c,r;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i = 0; i <n; i++)
    {
        cin>>c>>r;
        v.push_back({c-r,c+r});
    }
    sort(v.begin(),v.end(),compare);
    int count=1;
    int prev=0;
    for(int i=1;i<n;i++){
        if(v[i].first>=v[prev].second){
            count++;
            prev=i;
        }
    }
    cout<<n-count;
    return 0;
}