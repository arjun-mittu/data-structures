#include <iostream>
#include<queue>
using namespace std;
int main(){
    //priority_queue<int> pq; //maxheap 
    priority_queue<int,vector<int>,greater<int>> pq; //minheap 
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        pq.push(no);//O(Log(N))
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}