#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6,mod=10949;
int dp[maxn];
int po[4][maxn];
main()
{
    po[2][0]=1;
    po[3][0]=1;
    for(int i=2;i<=3;i++)
        for(int j=1;j<maxn;j++)
            po[i][j]=(po[i][j-1]*i)%mod;
    dp[1]=2;
    for(int i=2;i<maxn;i++)
        dp[i]=(dp[i-1]+2*(po[3][i-1]*po[2][i-1]+dp[i-1]))%mod;
    int n;
    cin>>n;
    cout<<dp[n]<<"  "<<(dp[n]*dp[n]*dp[n])%mod;
    return 0;
}
