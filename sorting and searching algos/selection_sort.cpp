#include <bits/stdc++.h>
using namespace std;
//pick smallest element and swap it with the first element
void selection_sort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[imin])
            {
                imin = j;
            }
        }
        swap(A[imin], A[i]);
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    selection_sort(A, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}