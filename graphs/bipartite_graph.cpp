#include<iostream>
#include<vector>
using namespace std;
bool dfs_helper(vector<int> graph[],int node,int *visited,int parent,int color){
    visited[node]=color;//1 or 2 ,both mean visited
    for(auto nbr:graph[node]){
        if(visited[nbr]==0){
            bool subprob=dfs_helper(graph,nbr,visited,node,3-color);
            if(!subprob){
                return false;
            }
        }
        else if(nbr!=parent && color==visited[nbr]){
            return false;
        }
    }
    return true;
}
bool dfs(vector<int> graph[],int N){
    int visited[N]={0}; // 0- not visited, 1- visited color is 1, 2 - visited color 2
    int color=1;
    bool ans= dfs_helper(graph,0,visited,-1,color);
    for(int i=0;i<N;i++){
        cout<<i<<"- Color"<<visited[i]<<endl;
    }
    return ans;
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> graph[N];
    while(M--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //bfs or dfs , by coloring the nodes at each stop(current node has color 1 , nbr should have a color 2)
    if(dfs(graph,N)){
        cout<<"yes";
    }
    else{
        cout<<"nope";
    }
    return 0;
}