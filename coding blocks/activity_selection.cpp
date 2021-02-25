#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int T;
    cin>>T;
    while (T > 0)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int f, s;
            cin >> f >> s;
            v.push_back(make_pair(f, s));
        }
        sort(v.begin(), v.end(), comparator);
        int count = 1;
        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= v[prev].second)
            {
                count++;
                prev = i;
            }
        }
        cout<<count<<endl;
        T--;
    }
    return 0;
}