#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(string s1, string s2)
{
    if(s1.length() < s2.length())
        return 1;
    else if(s1.length() > s2.length())
        return 0;
    else return s1 < s2;
}
int main(){
vector< string > data = {"b", "a", "c", "abc", "bca", "xy"};
sort(data.begin(), data.end(), comp);
for(string item : data)
        cout << item << " ";

        return 1;}
