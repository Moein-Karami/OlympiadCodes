///C


#include <bits/stdc++.h>
//#define int long long int
using namespace std;
const int maxn=5e3+10,mod=1e9+7;
int dp[maxn][maxn];
int s[maxn][maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    if(b<a)
    {
        a=n-a+1;
        b=n-b+1;
    }
    for(int i=1;i<b;i++)
        dp[i][0]=1,s[i][0]=(s[i-1][0]+1)%mod;
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<b;i++)
        {
            dp[i][j]=((s[b-1][j-1]-s[max(2*i-b,0)][j-1]-dp[i][j-1])%mod+mod)%mod;
            s[i][j]=(s[i-1][j]+dp[i][j])%mod;
            //cerr<<"I&J : "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[a][k];
}
