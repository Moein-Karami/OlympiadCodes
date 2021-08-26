#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+9;
int dp[10000];
main()
{
    int n,m;
    cin>>n>>m;
    if(m==0)
    {
        cout<<1;
        return 0;
    }
    dp[1]=n-1;
    for(int i=2;i<=m;i++)
    {
        dp[i]=dp[i-1]*(n-2);
        dp[i]=dp[i]%mod;
    }
    cout<<dp[m];
    return 0;
}
