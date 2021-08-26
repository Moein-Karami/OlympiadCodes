#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=12263,maxn=10000;
int dp[maxn][4];
int n;
int solve(int x,int y)
{
    if(x==n)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    dp[x][y]=(3*solve(x+1,y))%mod;
    for(int i=y;i<=2;i++)
        dp[x][y]=(dp[x][y]+solve(x+1,i)+1)%mod;
    return dp[x][y];
}
main()
{
    cin>>n;
    cout<<solve(0,0)%mod;
    return 0;
}
