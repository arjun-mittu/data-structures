#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    //insert
    m.insert(make_pair("mango", 100));
    pair<string, int> p;
    p.first = "apple";
    p.second = 120;
    m.insert(p);
    m["banana"] = 20;
    //update
    //search
    string fruit;
    cin >> fruit;

    m[fruit] += 22;
    auto it = m.find(fruit);
    if (it != m.end())
    {
        cout << "price of " << fruit << " is " << m[fruit] << endl;
    }
    else
    {
        cout << "nope" << endl;
    }
    //erase
    m.erase(fruit);

    //another way to find
    //it store unique keys only once
    if (m.count(fruit))
    {
        cout << "price of " << fruit << " is " << m[fruit] << endl;
    }
    else
    {
        cout << "nope" << endl;
    }
    m["lichi"] = 60;
    m["pinapple"] = 80;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}