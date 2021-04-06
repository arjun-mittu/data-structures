#include <iostream>
#include <climits>
using namespace std;
int max_sum_submatrix(int arr[][100], int n, int m)
{
    //col wise addition first
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            arr[i][j] += arr[i][j + 1];
        }
    }
    //row wise addtion
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            arr[i][j] += arr[i + 1][j];
        }
    }
    int result = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result = max(result, arr[i][j]);
        }
    }
    return result;
}
int main()
{
    int n, m;
    cin >> n >> m;
    /*int *arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }*/
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << max_sum_submatrix(arr, n, m);
}