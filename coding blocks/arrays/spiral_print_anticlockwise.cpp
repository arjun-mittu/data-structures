#include <iostream>
using namespace std;

void spiralprint(int a[][100], int m, int n)
{
    int sr = 0;
    int sc = 0;
    int er = n - 1;
    int ec = m - 1;
    while (sr <= er && sc <= ec)
    {
        for(int i=sr;i<=er;i++){
            cout<<a[i][sc]<<", ";
        }
        sc++;
        for(int i=sc;i<=ec;i++){
            cout<<a[er][i]<<", ";
        }
        er--;
        if(ec>sc){
            for(int i=er;i>=sr;i--){
                cout<<a[i][ec]<<", ";
            }
            ec--;
        }
        if(sr<=er){
            for(int i=ec;i>=sc;i--){
                cout<<a[sr][i]<<", ";
            }
            sr++;
        }
    }
    cout<<"END";
}
int main()
{
    int a[100][100] = {0};
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    spiralprint(a, m, n);
    return 0;
}
