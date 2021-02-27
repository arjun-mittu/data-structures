#include <iostream>
#include<set>
#include<climits>
using namespace std;
int main(){
    set<pair<int,int>> s;
    s.insert(make_pair(10,1));
    s.insert(make_pair(10,5));
    s.insert(make_pair(20,1));
    s.insert(make_pair(20,100));
    s.insert(make_pair(5,3));
    s.insert(make_pair(5,1));
    s.erase(s.find(make_pair(5,3)));
    s.insert(make_pair(5,4));
    //auto it=s.upper_bound(make_pair(20,1));
    //auto it=s.lower_bound(make_pair(20,1));
    //first greater than 10
    auto it=s.upper_bound(make_pair(10,INT_MAX));
    cout<<it->first<<" "<<it->second<<endl;
    for(auto p:s){
        cout<<p.first<<" & "<<p.second<<endl;
    }
    return 0;
}