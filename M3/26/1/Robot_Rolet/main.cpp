#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10567;
int dp[62];
int ans;
void solve(int n,int k)
{
    if(k==1)
        return;
    ans=(ans+(1LL<<(n-1)))%mod;
    if((1LL<<(n-1))>=k-1)
        solve(n-1,k-1);
    else
    {
        ans=(ans+dp[n-1])%mod;
        solve(n-1,k-(1LL<<(n-1)));
    }
}
main()
{
    dp[1]=2;
    for(int i=2;i<62;i++)
        dp[i]=((1LL<<(i-1))+2*dp[i-1])%mod;//,cerr<<"I : "<<i<<" "<<dp[i]<<endl;
    int n,k;
    cin>>n>>k;
    solve(n,k);
    cout<<ans;
    return 0;
}
