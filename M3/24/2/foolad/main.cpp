#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10513,maxn=3e3;
int dp[maxn][maxn];
int dp2[maxn][maxn];
int ans[maxn];
int p[maxn][maxn];
main()
{
    int n;
    cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
            dp[i][1]=1;
        for(int j=1;j<=n;j++)
        {
            dp[i][j]+=(dp[i-1][j]+dp[i-1][j-1])%mod;
            //cerr<<"I&J : "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }//cerr<<endl;
    for(int i=n;i>=1;i--)
        for(int j=1;j<=n;j++)
            dp2[i][j]=dp[i][j]-dp[i-1][j];//,cerr<<"I&J : "<<i<<" "<<j<<" "<<dp[i][j]<<endl;;
    //cerr<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=(dp[i][j]+mod)%mod;
            p[i][j]=(dp2[i][j]+p[i][j-1])%mod;
            //cerr<<"I&J : "<<i<<" "<<j<<" "<<p[i][j]<<endl;
        }
    }
    for(int i=2;i<=n;i++)
    {
        ans[i]=(2*ans[i-1])%mod;
        for(int j=2;j<=n;j++)
            ans[i]=(ans[i]+dp[i-1][j]*p[i][j-1])%mod;
    }
    int ret=1;
    for(int i=1;i<=n;i++)
        ret=(ret*ans[n])%mod;
    cout<<ret;
    return 0;
}
