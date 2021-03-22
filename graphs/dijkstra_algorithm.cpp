#include<bits/stdc++.h>
using namespace std;   
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> m;

    public:
        void addEdge(T u,T v,int dist,bool bidir=true){
            m[u].push_back({v,dist});
            if(bidir){
                m[v].push_back({u,dist});
            }

        }
        void printAdj(){
            for(auto j:m){
                 cout<<j.first<<"-->";
                 for(auto l:j.second){
                     cout<<"("<<l.first<<","<<l.second<<")";
                 }
                 cout<<endl;
            }
        }
        void dijsktraSSSP(T src){
            unordered_map<T,int> dist;
            //all distances to infinity
            for(auto j:m){
                dist[j.first]=INT_MAX;
            }
            //make set to find out node with minimum distance
            set<pair<int,T>> s;
            dist[src]=0;
            s.insert({0,src});
            while(!s.empty()){
                //find the pair at front
                auto p=*(s.begin());
                T node=p.second;
                int nodedist=p.first;
                s.erase(s.begin());
                //iterate over nbr of current node
                for(auto childPair:m[node]){
                    if(nodedist+childPair.second<dist[childPair.first]){
                        //in set updation of paticular node is not possible 
                        //so delete or remove and insert
                        T dest=childPair.first;
                        auto f=s.find({dist[dest],dest});
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        dist[dest]=nodedist+childPair.second;
                        s.insert({dist[dest],dest});
                    }
                }
            }
            //PRINT DISTANCES TO ALL NODES FROM SRC
            for(auto d:dist){
                cout<<d.first<<" distance= "<<d.second<<endl;
            }
        }
};

int main(){
   /* Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printAdj();
    g.dijsktraSSSP(1);*/
    Graph<string> India;
    India.addEdge("Amritsar","Delhi",1);
    India.addEdge("Amritsar","Jaipur",4);
    India.addEdge("Jaipur","Delhi",2);
    India.addEdge("Jaipur","Mumbai",8);
    India.addEdge("Bhopal","Agra",2);
    India.addEdge("Mumbai","Bhopal",3);
    India.addEdge("Agra","Delhi",1);
    India.printAdj();
    India.dijsktraSSSP("Amritsar");
    return 0;
}