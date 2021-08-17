#include <bits/stdc++.h>
using namespace std;
int partition(int *A, int s, int e)
{
    int pivot = A[e];
    int pinedx = s;
    int i=s;
    for (; i < e; i++)
    {
        if (A[i] <= pivot)
        {
            swap(A[i], A[pinedx]);
            pinedx++;
        }
    }
    swap(A[pinedx], A[e]);
    return pinedx;
}
void quick_sort(int *A,int s,int e){
    if(s>=e) return ;
    int pindex=partition(A,s,e);
    quick_sort(A,s,pindex-1);
    quick_sort(A,pindex,e);

}
int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    quick_sort(A, 0,5);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}