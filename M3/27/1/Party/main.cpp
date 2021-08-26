#include<bits/stdc++.h>
#define int long long int
using namespace std;
int k,mod=10289;
int dp[110][110];
int solve(int x,int y)
{
    if(x<0||y<0||x>k)
        return 0;
    if(x+y==0)
        return 1;
    if(dp[x][y])
        return dp[x][y];
    if(x)
        dp[x][y]=solve(x-1,y);
    else
        return dp[x][y]=solve(x+1,y-1);
    for(int i=1;i<=y;i++)
        dp[x][y]=(dp[x][y]+solve(x+i-1,y-i))%mod;
    //cerr<<x<<" "<<y<<" "<<dp[x][y]<<endl;
    return dp[x][y];
}
main()
{
    int n;
    cin>>n>>k;
    cout<<solve(1,n-1);
    return 0;
}
