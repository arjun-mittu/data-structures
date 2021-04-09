#include <iostream>
using namespace std;

int main()
{
    int sieve[1000001] = {0};
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i * i <= 1000000; i++)
        if (!sieve[i])
            for (int j = i * i; j <= 1000000; j += i)
                sieve[j] = 1;
    for (int i = 0; i <= 1000000; i++)
        if (sieve[i] == 0)
            sieve[i] = 1;
        else
            sieve[i] = 0;
    for (int i = 1; i <= 1000000; i++)
        sieve[i] += sieve[i - 1];
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != 0)
            cout << sieve[b] - sieve[a - 1] << endl;
        else
            cout << sieve[b] << endl;
    }
    return 0;
}
