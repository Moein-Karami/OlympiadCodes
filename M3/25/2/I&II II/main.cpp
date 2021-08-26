#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6,mod=10949;
int dp[2020][2020];
int po[4][maxn];
main()
{
    po[2][0]=1;
    po[3][0]=1;
    for(int i=2;i<=3;i++)
        for(int j=1;j<maxn;j++)
            po[i][j]=(po[i][j-1]*i)%mod;
    dp[1][0]=1;
    dp[1][1]=1;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=n;j++)
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
    }
    int ans=0;
    int x=po[2][n]-1;
    for(int i=n;i>=0;i--)
    {
        int t=x-dp[n][i]+1;
        ans=(ans+po[2][i]*(t+x)*(x-t+1)/2)%mod;
        x-=dp[n][i];
    }
    cout<<(ans+mod)%mod;
    return 0;
}
