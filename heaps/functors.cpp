#include <bits/stdc++.h>
using namespace std;
class fun
{
public:
    void operator()(string s)
    {
        cout << "inside " << s;
    }
};
class Person
{
    public:
    string name;
    int age;
    Person()
    {
    }
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
};
class PersonCompare
{
public:
    bool operator()(Person A, Person B)
    {
        return A.age < B.age;
    }
};
int main()
{
    //fun f;//constructor
    //f("c++");//overloaded () operator =function call where f is an object
    int n;
    cin >> n;
    priority_queue<Person, vector<Person>, PersonCompare> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        Person p(name, age);
        pq.push(p);
    }
    int k=3;
    for(int i=0;i<k;i++){
        Person p=pq.top();
        cout<<p.name<<" "<<p.age<<endl;
        pq.pop();
    }
    return 0;
}