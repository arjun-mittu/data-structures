#include <iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, pair<int, int>> node;
vector<int> mergeksortedarray(vector<vector<int>> v){
    vector<int> result;
    priority_queue<node,vector<node>,greater<node>> pq;
    for(int i=0;i<v.size();i++){
        pq.push({v[i][0],{i,0}});
    }
    while (!pq.empty())
    {
        node current=pq.top();
        pq.pop();
        int element=current.first;
        int x=current.second.first;
        int y=current.second.second;
        result.push_back(element);
        if(y+1<v[x].size()){
            pq.push({v[x][y+1],{x,y+1}});
        }
        
    }
    
    return result;
}
int main()
{
    int k,n;
    cin>>k>>n;
    vector<vector<int>> v;
    int data;
    for(int i=0;i<k;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            cin>>data;
            temp.push_back(data);
        }
        v.push_back(temp);
    }
    vector<int> ans=mergeksortedarray(v);   
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}