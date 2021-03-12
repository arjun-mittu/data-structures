#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include<queue>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    int d,f;
    for(int i=0;i<n;i++){
        cin>>d>>f;
        v.push_back({d,f});
    }
    int D,F;
    cin>>D>>F;
    for(int i=0;i<n;i++){
        v[i].first=D-v[i].first;
    }
    int flag=0,ans=0;
    sort(v.begin(),v.end(),compare);
    //previous city
    priority_queue<int> pq;
    int prev=0;
    int x=0;// current city
    while(x<n){
        //we have fuel to go to next city
        if(F>=(v[x].first-prev)){
            F=F-(v[x].first-prev);// check this line
            pq.push(v[x].second);
            prev=v[x].first;
        }
        else{
            //check if ypu have fueling station visited in pq
            if(pq.empty()){
                flag=1;
                break;
            }
            //refule truck from with higher capacity
            F+=pq.top();
            //remove from pq
            pq.pop();
            ans++;
            continue;
        }
        x++;
    }
    if(flag==1){
        cout<<-1<<endl;
    }
    else{
        D=D-v[n-1].first;
        if(F>=D){
            //cout<<ans<<endl;
        }
        else{
            while(F<D){
                if(pq.empty()){
                    flag=1;
                    break;
                }
                F+=pq.top();
                pq.pop();
                ans++;
            }
        }   
    }
    if(flag==1){
        cout<<-1<<endl;
    }
    cout<<ans<<endl;
    return 0;
}