#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[110];
int mod=229939;
int solve(int x)
{
    if(x==0)
        return 1;
    if(dp[x])
        return dp[x];
    for(int i=1;i<=x;i++)
        dp[x]=(dp[x]+solve(x-i))%mod;
    return dp[x];
}
main()
{
    cout<<solve(100);
    return 0;
}
