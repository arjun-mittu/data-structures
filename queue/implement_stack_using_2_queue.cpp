#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
template<typename T>
class stack{
    queue<T> q1,q2;
public:
    void push(T x){
        q1.push(x);
    }
    void pop(){
        //remove the the last added element from q1
        //we have to move first n-1 elements in q2
        // interchange the names of q1 and q2
        if(q1.empty()){
            return;
        }
        while(q1.size()>1){
            T element=q1.front();
            q2.push(element);
            q1.pop();
        }
        //last element
        q1.pop();
        //swap names of q1 and q2
        swap(q1,q2);
    }
    T top(){
        while(q1.size()>1){
            T element=q1.front();
            q2.push(element);
            q1.pop();
        }
        //last element
        T element=q1.front();
        q1.pop();
        q2.push(element);
        //swap names of q1 and q2
        swap(q1,q2);
        return element;
    }
    int size(){
        return q1.size()+q2.size();
    }
    bool empty(){
        return size()==0;
    }
};
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}