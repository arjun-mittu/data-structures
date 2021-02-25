#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    char s;
    cin >> s;
    if (isupper(s))
    {
        cout << "UPPERCASE";
    }
    else if (islower(s))
    {
        cout << "lowercase";
    }
    else
    {
        cout << "Invalid";
    }
    return 0;
}