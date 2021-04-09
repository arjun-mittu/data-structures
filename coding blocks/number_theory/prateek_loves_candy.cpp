#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<ll> primeSieve(ll *p, ll n)
{
    p[0] = p[1] = 0;
    p[2] = 1;
    for (ll i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }
    for (ll i = 3; i <= n; i += 2)
    {
        if (p[i])
        {
            for (ll j = i * i; j <= n; j += 2 * i)
            {
                p[j] = 0;
            }
        }
    }
    vector<ll> primes;
    primes.push_back(2);
    for (ll i = 3; i <= n; i++)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}
int main()
{
    int t;
    cin >> t;
    vector<ll> ans;
    ll size = 500002;
    ll p[size] = {0};
    ans = primeSieve(p, size);
    while (t--)
    {
        ll n;
        cin >> n;
        cout << ans[n - 1] << endl;
    }
    return 0;
}