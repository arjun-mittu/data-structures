#include <iostream>
using namespace std;
int main()
{
    int a[11][11];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int col = 0; col < m; col++)
    {
        if (col % 2 == 0)
        {
            for(int i=0;i<n;i++){
                cout<<a[i][col]<<", ";
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                cout<<a[i][col]<<", ";
            }
        }
    }
    cout<<"END";
    return 0;
}
