#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0)
    {
        int n;
        cin>>n;
        priority_queue<int> leftheap;
        priority_queue<int,vector<int>,greater<int>> rightheap;
        int med;
        int data;
        cin>>data;
        med=data;
        leftheap.push(data);
        cout<<med<<" ";
        for(int i=1;i<n;i++){
            cin>>data;
            if(leftheap.size()>rightheap.size()){
                if(data<med){
                    int temp=leftheap.top();
                    leftheap.pop();
                    rightheap.push(temp);
                    leftheap.push(data);
                }
                else{
                    rightheap.push(data);
                }
                med=(leftheap.top()+rightheap.top())/2;
            }
            else if(leftheap.size()==rightheap.size()){
                if(data<med){
                    leftheap.push(data);
                    med=leftheap.top();
                }
                else{
                    rightheap.push(data);
                    med=rightheap.top();
                }
            }
            else{
                if(data>med){
                    leftheap.push(rightheap.top());
                    rightheap.pop();
                    rightheap.push(data);
                }
                else{
                    leftheap.push(data);
                }
                med=(leftheap.top()+rightheap.top())/2;
            }
            cout<<med<<" ";
        }
        cout<<endl;
        t--;
    }
    

    return 0;
}