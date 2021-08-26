#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=100;
int a[maxn][maxn];
int dp[maxn][maxn][4];
int n=80;
int inf=1e9;
int solve(int x,int y,int tp)
{
    if(x<1||x>n)
        return inf;
    if(y>n)
        return 0;
    if(dp[x][y][tp])
        return dp[x][y][tp];
    if(y==n)
        return a[x][y];
    dp[x][y][tp]=a[x][y]+solve(x,y+1,0);
    if(tp!=1)
        dp[x][y][tp]=min(dp[x][y][tp],solve(x-1,y,2)+a[x][y]);
    if(tp!=2)
        dp[x][y][tp]=min(dp[x][y][tp],solve(x+1,y,1)+a[x][y]);
    return dp[x][y][tp];
}
main()
{
    fstream in("test.txt",ios::in);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            in>>a[i][j];
    int ans=inf;
    for(int i=1;i<=n;i++)
        ans=min(ans,solve(i,1,0));
        cout<<ans;
    return 0;
}
