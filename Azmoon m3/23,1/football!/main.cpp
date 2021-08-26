#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10357;
int ans,dp[10010][2],dp1[10010];
main()
{
    int tmp=1;
    for(int i=1;i<=10000;i++)
        tmp=(tmp*2)%mod;
    tmp--;
    int t=1;
    for(int i=1;i<=mod-2;i++)
        t=(t*2)%mod;
    dp[1][0]=(tmp*(tmp+1)*t)%mod;
    dp[1][1]=(3*dp[1][0])%mod;
    dp1[1]=(dp[1][1])%mod;
    for(int i=2;i<=10000;i++)
    {
        dp[i][0]=(2*dp1[i-1])%mod;
        dp[i][1]=(3*dp1[i-1])%mod;
        dp1[i]=(dp[i][0]+dp[i][1])%mod;
    }
    ans=dp[1][1];
    for(int i=2;i<=10000;i++)
        ans=(ans+dp1[i])%mod;
    cout<<ans;
    return 0;
}
