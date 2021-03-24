#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int u, int v)
    {
        l.push_back({u, v});
    }
    // Find
    int findSet_path_compression_opt(int i, int parent[])
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return parent[i] = findSet_path_compression_opt(parent[i], parent);
    }
    //union
    void union_set(int x, int y, int parent[],int rank[])
    {
        int s1 = findSet_path_compression_opt(x, parent);
        int s2 = findSet_path_compression_opt(y, parent);
        if (s1 != s2)
        {
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    bool contains_cycle()
    {
        //DSU logic to check if graph contains cycle or not
        int *parent = new int[V];
        int *rank=new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i]=1;
        }
        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet_path_compression_opt(i, parent);
            int s2 = findSet_path_compression_opt(j, parent);
            if (s1 != s2)
            {
                union_set(s1, s2, parent,rank);
            }
            else
            {
                cout << "same " << s1 << " and " << s2 << endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    //g.addEdge(3,0);
    cout << g.contains_cycle();
    return 0;
}