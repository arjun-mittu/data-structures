#include <bits/stdc++.h>
using namespace std;
#define N 8
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
bool issafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
bool solve(int x, int y, int movei, int sol[N][N], int *xmove, int *ymove)
{
    int k, next_x, next_y;
    if (movei == N * N)
        return true;
    for (k = 0; k < 8; k++)
    {
        next_x = x + xmove[k];
        next_y = y + ymove[k];
        if (issafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solve(next_x, next_y, movei + 1, sol, xmove, ymove))
                return true;
            sol[next_x][next_y] = -1;
        }
    }
    return false;
}
int main()
{
    int sol[N][N];
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            sol[x][y] = -1;
        }
    }
    int xmove[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
    int ymove[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
    sol[0][0] = 0;
    if (solve(0, 0, 1, sol, xmove, ymove) == 0)
    {
        cout << "not possible" << endl;
    }
    else
    {
        printSolution(sol);
    }
    return 0;
}