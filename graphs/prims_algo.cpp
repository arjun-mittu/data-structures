#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
class Graph{
    // adjacency list we need neighbours
    vector<pair<int,int>> *l;
    int V;
    public:
        Graph(int n){
            V=n;
            l=new vector<pair<int,int>>[n];
        }
        void addEdge(int x,int y,int w){
            l[x].push_back({y,w});
            l[y].push_back({x,w});
        }
        int prim_mst(){
            //most important stuff
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
            //another array 
            //visited array that denotes whether a node has been included in MST or not
            bool *visited=new bool[V]{0};
            int ans=0;
            //begin
            Q.push({0,0}); //weight, next node to node like from 1 to 2 2 is presnet here
            while(!Q.empty()){
                //pick out edge with min weight
                auto best=Q.top();
                Q.pop();
                int to=best.second;
                int weight=best.first;
                if(visited[to]){
                    //discard, and continue
                    continue;
                }
                //otherwise take current edge
                ans+=weight;
                visited[to]=1;
                //add the new edges in the queue
                for(auto x:l[to]){
                    if(visited[x.first]==0){
                        Q.push({x.second,x.first});
                    }
                }
            }
            return ans;
        }
};

int main(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);//spoj mei indexing 1 se hai isliye -1 kiya
    }
    cout<<g.prim_mst()<<endl;
    return 0;
} 