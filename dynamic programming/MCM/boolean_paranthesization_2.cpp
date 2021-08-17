//galat
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int dpt[n][n];
    int dpf[n][n];

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                char ch = s1[i];
                if (ch == 'T')
                {
                    dpt[i][j] = 1;
                    dpf[i][j] = 0;
                }
                else
                {
                    dpf[i][j] = 1;
                    dpt[i][j] = 0;
                }
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    char opr = s2[k];
                    int ltc = dpt[i][k];
                    int rtc = dpt[k + 1][j];
                    int lfc = dpf[i][k];
                    int rfc = dpf[k + 1][j];

                    if (opr == '&')
                    {
                        dpt[i][j] = ltc * rtc;
                        dpf[i][j] = lfc * rtc + ltc * rfc + lfc * rfc;
                    }
                    else if (opr == '|')
                    {
                        dpt[i][j] = ltc * rtc + lfc * rtc + ltc * rfc;
                        dpf[i][j] = lfc * rfc;
                    }
                    else
                    {
                        dpt[i][j] = ltc * rfc + rtc * lfc;
                        dpf[i][j] = lfc * rfc + ltc * rtc;
                    }
                }
            }
        }
    }
    cout << dpt[0][n - 1] << endl;
    return 1;
}