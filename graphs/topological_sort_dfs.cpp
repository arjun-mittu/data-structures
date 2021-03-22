#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> l; //not wieghted graph
public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        //l[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool> &visited,list<T> &ordering)
    {
        //recursive function that will traverse the graph
       
        visited[src] = true;
        //go to allnbr of that node that is not visited
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited,ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        //mark all the nodes as not visited in beginning
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                dfs_helper(node, visited,ordering);
            }
        }
        for(auto node:ordering){
            cout<<node<<endl;
        }
    }
};
int main(){
    Graph<string> g;
    g.addEdge("python","datapreprocessing");
    g.addEdge("python","pytorch");
    g.addEdge("python","ML");
    g.addEdge("datapreprocessing","ML");
    g.addEdge("pytorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","Facerecognition");
    g.addEdge("dataset","Facerecognition");
    g.dfs();
    return 0; 
}