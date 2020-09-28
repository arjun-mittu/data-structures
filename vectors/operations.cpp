#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> d{1,2,3,4,5};
    // push back O(1) for most of the time
    d.push_back(16);
    // pop from O(1) for most the cases
    d.pop_back();
    d.insert(d.begin()+3,100);//O(n) number of elements added 
    /*d.insert(d.begin()+3,4,100);*/
    d.erase(d.begin()+3);
    /*d.erase(d.begin()+2,d.begin()+5)*/
    //we avoid shrink
    // size increases when elements are added
    /*d.reserve(4); to reduce size*/

    //remove all elements of vector, doesnt delete memory occupied
    //d.clear()
    if(d.empty()){
        cout<<"empty";
    }
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<d.front();
    cout<<d.back();
    int n;
    cin>>n;
    //doubling
    
   vector <int> v;
   v.reserve(1000);
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        v.push_back(no);
    }

    return 0;
}