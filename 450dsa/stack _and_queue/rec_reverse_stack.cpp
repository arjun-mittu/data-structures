#include<bits/stdc++.h>
using namespace std;

void insertatbottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int data = s.top();
    s.pop();
    insertatbottom(s, x);
    s.push(data);
}

void reversestack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int val=s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,val);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reversestack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}