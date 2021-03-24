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
        //l.push_back({v, u});
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
    void union_set(int x, int y, int parent[], int rank[])
    {
        int s1 = findSet_path_compression_opt(x, parent);
        int s2 = findSet_path_compression_opt(y, parent);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    int pairing()
    {
        // N-rank[find(1)]
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
        int ans=0;
        for(auto edge:l){
            int i=edge.first;
            int j=edge.second;
            int s1=findSet_path_compression_opt(i,parent);
            int s2=findSet_path_compression_opt(j,parent);
            union_set(s1,s2,parent,rank);
        }
        //got to all the nodes
        for(int i=0;i<V;i++){
            ans+=V-rank[findSet_path_compression_opt(i,parent)];
        }
        delete [] parent;
        delete [] rank;
        //divide by 2 because the ans is caculated from all the sides
        return ans/2;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.pairing();
    return 0;
}