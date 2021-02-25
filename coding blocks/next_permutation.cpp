#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int n;
        cin >> n;
        int arr[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        next_permutation(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        T--;
    }
    return 0;
}