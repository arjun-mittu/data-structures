#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int arr[1000];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int max = INT_MIN;
        int sum;
        int width = 0;
        while (width < n)
        {
            int sidx = 0;
            while (sidx + width < n)
            {
                sum = 0;
                for (int j = sidx; j <= sidx + width; j++)
                {
                    sum = sum + arr[j];
                }
                if (sum > max)
                {
                    max = sum;
                }
                sidx = sidx + 1;
            }
            width = width + 1;
        }
        cout << max;
        T--;
    }
    return 0;
}