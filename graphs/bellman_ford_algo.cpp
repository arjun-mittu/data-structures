#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int V,int src,vector<vector<int>> edges){
    //create a vector
    vector<int> dist(V+1,INT_MAX);
    dist[src]=0;
    //relax edges V-1 times
    
    for(int i=0;i<V-1;i++){
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){ //INT_MAX + any number it becomes negative
                dist[v]=dist[u]+wt;
            }
        }
    }
    //negative wt cycle 
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        { //INT_MAX + any number it becomes negative
            cout<<"negative wt cycle found";
            exit(0);
        }
    }
    return dist;

}
int main(){
    //edge list
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges; //(a,b,3)
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    //bellman algorithm
    vector<int> distances=bellman_ford(n,1,edges);
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<"node "<<i<<" is at distance of= "<<distances[i]<<endl;
    }
    return 0;
}