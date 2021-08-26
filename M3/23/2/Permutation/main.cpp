#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10711;
int ans;
int dp[3000][3000];
int f[3000];
int c[3000][3000];
main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<2000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    f[0]=1;
    for(int i=1;i<=n;i++)
        f[i]=(f[i-1]*i)%mod;
    for(int i=0;i<=n;i++)
        for(int j=i;j<2000;j++)
            dp[i][j]=f[i];
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int e=1;e<=i;e++)
                dp[i][j]=(dp[i][j]+c[i-1][e-1]*dp[e-1][j-1]*dp[i-e][j])%mod;
            //cerr<<"I & J : "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<(dp[n-1][k]*dp[n-1][k]*dp[n-1][k])%mod;
    return 0;
}
