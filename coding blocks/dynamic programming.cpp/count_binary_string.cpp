#include <iostream>
using namespace std;

int countStrings(long long int n)
{
    long long int a[n], b[n];
    a[0] = b[0] = 1;
    for (long long int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }
    return a[n - 1] + b[n - 1];
}
int main()
{
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
    cout << countStrings(n) << endl;}
    return 0;
}