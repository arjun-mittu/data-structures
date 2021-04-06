#include <iostream>
#include <algorithm>
using namespace std;

void rotateimg(int a[][1000], int m, int n)
{
    for (int row = 0; row < n; row++)
    {
        int start_col = 0;
        int end_col = n - 1;
        while (start_col < end_col)
        {
            swap(a[row][start_col], a[row][end_col]);
            start_col++;
            end_col--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
    }
}
int main()
{
    int a[1000][1000] = {0};
    int n, m;
    cin >> n;
    m=n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    rotateimg(a, m, n);
    return 0;
}
