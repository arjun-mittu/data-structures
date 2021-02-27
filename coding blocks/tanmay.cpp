#include <bits/stdc++.h>
using namespace std;
vector<string> ans;

void solve(int n, string str, int start, int end)
{
    if (end == n)
    {
        ans.push_back(str);
        return;
    }
    solve(n, str + '(', start + 1, end);
    solve(n, str + ')', start, end + 1);
}

int main()
{
    int n;
    cin >> n;
    solve(n, "", 0, 0);
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}