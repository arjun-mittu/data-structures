#include <iostream>
using namespace std;
int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char park[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> park[i][j];
        }
    }
    bool succes = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s < k)
            {
                succes = false;
                break;
            }
            if (park[i][j] == '.')
            {
                s = s - 2;
            }
            else if (park[i][j] == '*')
            {
                s = s + 5;
            }
            else
            {
                break;
            }
            if (j != m - 1)
            {
                s--;
            }
        }
    }
    if (succes)
    {
        cout << "Yes\n"
             << s;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}