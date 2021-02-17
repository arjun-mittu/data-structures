#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
void asci_diff(string inp, int i)
{
    if (i == inp.length() - 1)
    {
        cout << inp;
        return;
    }
    string i1, i2, i3;
    i1 = inp.substr(0, i + 1);
    i3 = inp.substr(i + 1, inp.length() - 1 - i);
    int diff = i3[0] - i1[i];
    i2 =to_string(diff);
    string new_inp=i1+i2+i3;
   // cout<<new_inp;
    asci_diff(new_inp,i+1+i2.length());
}
int main()
{
    string inp;
    cin >> inp;
    asci_diff(inp, 0);
    return 0;
}