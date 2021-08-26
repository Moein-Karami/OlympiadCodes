#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=22943;
int dp[10][10][20];
int solve(int x,int y,int h)
{
    if(dp[x][y][h])
        return dp[x][y][h];
    if(x==4&&y==4&h==16)
        return 1;
    if(x>7||x<1||y>7||y<1||h>16)
        return 0;
    int &ret=dp[x][y][h];
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if(j!=i&&j!=-i)
                ret+=solve(x+i,y+j,h+1);
    return ret;
}
main()
{
    cout<<solve(4,4,0)%mod;
    return 0;
}
