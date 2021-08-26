#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=12263;
int dp[10010][3];
int ans[10010];
int t(int x)
{
    int ret=1;
    for(int i=1;i<=x;i++)
        ret=(ret*3)%mod;
    return ret;
}
main()
{
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][0]=1;
    for(int i=2;i<=10000;i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(j==0)
            {
                dp[i][j]=(t(i-1)+2*dp[i-1][j])%mod;
            }
            else if(j==1)
            {
                dp[i][j]=(t(i-1)+2*(dp[i-1][j]+dp[i-1][j-1]))%mod;
            }
            else
            {
                dp[i][j]=(t(i-1)+2*(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j-2]))%mod;
            }
        }
    }
    for(int i=2;i<=10000;i++)
        ans[i]=(dp[i][0]+dp[i][1]+dp[i][2])%mod;
    cout<<ans[10000];
    return 0;
}
