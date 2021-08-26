#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6,mod=10559;
int dp[maxn],po[maxn];
int p(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
main()
{
    po[0]=1;
    for(int i=1;i<maxn;i++)
        po[i]=(po[i-1]*2)%mod;
    int n;
    cin>>n;
    dp[0]=1;
    dp[1]=po[n-1]-1;
    for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1]*(po[n-2]-1)+(po[n-2]*p(2,(i-1)*(n-1))))%mod;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[n-i]*p(2,(i-1)*(n-1)))%mod;
    cout<<ans<<endl;
    return 0;
}
