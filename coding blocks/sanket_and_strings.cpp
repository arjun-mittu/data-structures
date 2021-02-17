#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    int count_a = 0;
    int count_b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            count_a=count_a+1;
        }
        if (s[i] == 'b')
        {
            count_b=count_b+1;
        }
    }
    cout<<count_a;
    return 0;
}