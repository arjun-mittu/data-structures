#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.size(), m = t.size();
    int l = 0, r;
    map<char, int> freq_s, freq_t;
    for (auto x : t)
    {
        freq_t[x]++;
    }
    int resl = -1, resr = 1e9;
    for (r = 0; r < n; r++)
    {
        //check whether l to r is a good string
        freq_s[s[r]]++;
        bool good = true;
        for (auto x : freq_t)
        {
            //x is pair of char and int
            if ((freq_s.count(x.first) == 0) || freq_s[x.first] < x.second)
            {
                good = false;
                break;
            }
        }
        if (!good)
        {
            continue;
        }
        //move l forward part for every r
        while (l <= r && l < n && (freq_t.count(s[l]) == 0 || freq_s[s[l]] > freq_t[s[l]]))
        {
            freq_s[s[l]]--;
            if (freq_s[s[l]] == 0)
                freq_s.erase(s[l]);
            l++;
        }
        //cout<<l<<" "<<r<<endl;
        if(resr-resl+1>r-l+1){
            resl=l;
            resr=r;
        }
    }
    //cout<<resl<<" "<<resr;
    if(resl==-1){
        cout<<"No String";
    }
    else{
        cout<<s.substr(resl,resr-resl+1);
    }
    return 0;
}