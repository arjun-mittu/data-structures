#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> vect{
        {4, 2, 3},
        {7, 5, 6},
        {1, 8, 9}};
    auto comp = [](const vector<int> &u, const vector<int> &v) {
        return u[0] < v[0];
    };
    sort(vect.begin(), vect.end(), comp);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}
// auto cmp=[](const vector<int> &u,const vector<int> &v){ return u[0]<v[0];};