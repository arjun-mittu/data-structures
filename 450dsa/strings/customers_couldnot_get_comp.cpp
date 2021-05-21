#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string seq;
    cin >> seq;
    int comp_used = 0;
    int res = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < seq.size(); i++)
    {
        if (m[seq[i]] == 0)
        {
            m[seq[i]] = 1;
            if (comp_used < n)
            {
                comp_used++;
                cout << "add allocated ";
                cout << seq[i] << " " << i << " " << comp_used << endl;
                m[seq[i]] = 2;
            }
            else if (comp_used == n)
            {
                cout << "add ";
                cout << seq[i] << " " << i << " " << comp_used << endl;
                res++;
            }
        }
        else if (m[seq[i]] == 1)
        {
            m[seq[i]] = 0;
            cout << "sub ";
            cout << seq[i] << " " << i << " " << comp_used << endl;
        }
        else if (m[seq[i]] == 2)
        {
            m[seq[i]] = 0;
            comp_used--;
            cout << "sub allocated ";
            cout << seq[i] << " " << i << " " << comp_used << endl;
        }
    }
    cout << res;
    return 0;
}