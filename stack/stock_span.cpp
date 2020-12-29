#include<iostream>
#include<stack>
using namespace std;
void stockspan(int prices[],int n,int span[]){
    stack<int> s; //indices of the days
    s.push(0);
    span[0]=1;
    for(int i=1;i<=n-1;i++){
        int currentprices=prices[i];
        //topmost element that is higher than current prices
        while(!s.empty() && prices[s.top()]<=currentprices){
            s.pop();
        }
        if(!s.empty()){
        int prev_highest=s.top();
        span[i]=i-prev_highest;}
        else{
            span[i]=i+1;
        }
        //push this element into the stack
        s.push(i);
    }
}
int main(){
    int prices[]={100,80,60,70,60,75,85};
    int n=sizeof(prices)/sizeof(int);
    int span[1000]={0};
    stockspan(prices,n,span);
    for (int i = 0; i < n; i++)
    {
        cout<<span[i]<<" ";
    }
    
    return 0;
}