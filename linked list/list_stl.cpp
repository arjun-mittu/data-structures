#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l;
    list<int> l1{1,2,3,4};
    list<string> l2{"apple","banana","aam"};
    l2.push_back("pine");
    l2.sort();
    l2.reverse();

    cout<<l2.front()<<endl;
    l2.pop_front();
    l2.push_front("liww");
    cout<<l2.back()<<endl;
    l2.pop_back();
    for(auto it=l2.begin();it!=l2.end();it++){
        cout<<(*it)<<"->";
    }
    cout<<endl;
    //string f;
    //cin>>f;
    //l2.remove(f);
    auto it=l2.begin();
    it++;
    l2.erase(it);
    it=l2.begin();it++;
    l2.insert(it,"fruitjouice");
    for(auto s:l2){
        cout<<s<<"->";
    }

    return 0;
}

