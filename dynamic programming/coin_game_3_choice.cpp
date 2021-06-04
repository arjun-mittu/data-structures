// C++ program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;

// To find winner of game
bool findWinner(int x, int y, int n)
{
    // To store results
    bool dp[n+1];
    dp[0]=false;
    dp[1]=true;
    for(int i=2;i<=n;i++){
        if(i-1>=0 && dp[i-1]==false){
            dp[i]=true;
        }
        if (i - x >= 0 && dp[i - x] == false)
        {
            dp[i] = true;
        }
        if (i - y >= 0 && dp[i - y] == false)
        {
            dp[i] = true;
        }
    }
    return dp[n];
}

// Driver program to test findWinner();
int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}
