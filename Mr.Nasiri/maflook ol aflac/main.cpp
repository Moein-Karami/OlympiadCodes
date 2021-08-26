#include <iostream>

using namespace std;
int a[1010][1010];
int dp[1010][1010];
int solve(int i,int j)
{
    if(dp[i][j])
        return dp[i][j];
    int x=0;
    if(a[i+1][j]<a[i][j])
        x=solve(i+1,j);
    if(a[i][j+1]<a[i][j])
        x=max(x,solve(i,j+1));
    if(a[i][j-1]<a[i][j])
        x=max(x,solve(i,j-1));
    if(a[i-1][j]<a[i][j])
        x=max(x,solve(i-1,j));
    x++;
        return dp[i][j]=x;
}
int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(i==n+1||j==m+1||i==0||j==0)
                a[i][j]=1e9;
            else
                cin>>a[i][j];
        }

    }
    int y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            solve(i,j);
    int x=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(x<dp[i][j])
                x=dp[i][j];
    }
    cout<<x;
    return 0;
}
