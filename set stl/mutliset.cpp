#include<bits/stdc++.h>
using namespace std;
typedef multiset<int>::iterator It;
int main(){
    int arr[]={10,20,30,20,30,30,30,10,30};
    int n=sizeof(arr)/sizeof(int);
    multiset<int> m(arr,arr+n);
    m.erase(20);//all occurences are erased
    m.insert(80);
    for (int x : m)
    {
        cout << x << ",";
    }
    cout<<endl;
    cout<<m.count(10)<<endl;//number of 10

    //find
    auto it=m.find(30);
    cout<<(*it)<<endl;
    //get all element equal  to 30
    pair<It,It> range=m.equal_range(30);
    for(auto it=range.first;it!=range.second;it++){
        cout<<*it<<"-";
    }
    cout<<endl;
    //lower bound and upper bound
    for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++){
        cout<<*it<<"-";
    }
    return 0;
}