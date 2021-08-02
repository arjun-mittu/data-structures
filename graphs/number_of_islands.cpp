#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &arr, int i, int j, vector<vector<bool>> &visited)
{
    if(i<0 || j<0 || i>=arr.size() ||j>=arr[i].size() ||arr[i][j]==1 || visited[i][j]==true) return;
    visited[i][j] = true;
    solve(arr, i - 1, j, visited);
    solve(arr, i, j + 1, visited);
    solve(arr, i, j - 1, visited);
    solve(arr, i + 1, j, visited);
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && visited[i][j] == false)
            {
                solve(arr, i, j, visited);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}