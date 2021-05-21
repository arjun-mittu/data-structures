#include <bits/stdc++.h>
using namespace std;
bool check(string a, string b)
{
    if (a.size() != b.size())
        return false;
    int n = a.size();
    int m[256];
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        m[b[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (m[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string a = "EACBD", b = "EABCD";
    if (check)
    {
        int res = 0;
        for (int i = a.size() - 1, j = a.size() - 1; i >= 0;)
        {
            while (i >= 0 && a[i] != b[j])
            {
                i--;
                res++;
            }
            if (i >= 0)
            {
                i--;
                j--;
            }
        }
        cout << res;
    }
    else
    {
        cout << "not possible" << endl;
    }
    return 0;
}