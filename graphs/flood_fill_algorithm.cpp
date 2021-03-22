#include <bits/stdc++.h>
using namespace std;
int R, C;
//        W,N,E,S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void floodFill(char mat[][50], int i, int j, char ch, char color)
{
    //base case
    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return;
    }
    //figure boundary condition
    if (mat[i][j] != ch)
    {
        return;
    }
    mat[i][j] = color;
    //recursive call
    for (int k = 0; k < 4; k++)
    {
        floodFill(mat, i + dx[k], j + dy[ch], ch, color);
    }
}
int main()
{
        cin >> R >> C;
        char input[15][50];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> input[i][j];
            }
        }
        floodFill(input,8,13,'.','r');
        //print matrix
        return 0;
}