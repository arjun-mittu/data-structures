#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int T;
    cin >> T;
    for(int j=1;j<=T;j++)
    {
        int n, k, barn, time;
        cin >> n >> k >> barn >> time;
        int x[n], v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        int cnt = 0;
        int np=0;
        for(int i=n-1;i>=0;i--){
            int req_dist=barn-x[i];
            int ach_dist=time*v[i];
            if(req_dist<=ach_dist){
                cnt++;
                if(np>0){
                    ans+=np;
                }
            }
            else{
                np++;
            }
            if(cnt>=k) break;
        }
        if (cnt >= k)
        {
            cout <<"Case #"<<j<<": "<< ans << endl;
        }
        else
        {
            cout << "Case #" << j << ": "<< "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}