#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[110];
int ans;
int mod=1e9+9;
void solve(int a,int x)
{
    if(!a)
        return;
    if(a==(1LL<<x))
    {
        ans=(ans+dp[x]-1)%mod;
        return ;
    }
    else if(a>((1LL<<(x-1))))
    {
        ans=(ans+(1LL<<(x-1)));
        ans=(ans+dp[x-1])%mod;
        a-=(1LL<<(x-1));
        solve(a,x-1);
    }
    else
    {
        ans=(ans+(1LL<<(x-1)));
        solve(a-1,x-1);
    }

}
main()
{
    int a=12345678987654321;
    dp[1]=2;
    for(int i=2;i<=60;i++)
        dp[i]=((1LL<<(i-1))+2*dp[i-1])%mod;
    solve(a-1,60);
    cout<<ans;
    return 0;
}
