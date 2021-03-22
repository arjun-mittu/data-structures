#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <climits>
#include<stack>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> l; //not wieghted graph
public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool> &visited){
        //recursive function that will traverse the graph
        cout<<src<<" ";
        visited[src]=true;
        //go to allnbr of that node that is not visited
        for(T nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> visited;
        //mark all the nodes as not visited in beginning
        for(auto p:l){
            T node=p.first;
            visited[node]=false;
        }
        dfs_helper(src,visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 0);
    g.dfs(0);
    return 0;
}