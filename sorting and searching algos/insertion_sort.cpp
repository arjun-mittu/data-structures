#include <bits/stdc++.h>
using namespace std;
//make partion left side sorted elements and right side unsorted elements pcik one element form right and plca in left
void insertion_sort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int value=A[i];
        int j=i-1;
        while(j>=0 && A[j]>value){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=value;
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    insertion_sort(A, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}