#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5,mod=1e9+7;
int dp[maxn][maxn];
int dp2[maxn][maxn];
int ans;
int p[maxn];
int fit(int x,int y)
{
    if(y<0)
        return 0;
    if(x==0)
        return 1;
    if(dp2[x][y])
        return dp2[x][y];
    return dp2[x][y]=(fit(x-1,y-1)+fit(x-1,y+1))%mod;
}
int solve(int x,int y)
{
    if(y>x)
        return 0;
    if(x==0)
    {
        if(y==0)
            return 1;
        else
            return 0;
    }
    if(dp[x][y])
        return dp[x][y];
    int &ret=dp[x][y];
    if(y==0)
    {
        ret=(ret+fit(x,0))%mod;
        return ret;
    }
    return ret=(solve(x-1,y-1)+solve(x-1,y+1))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int tmp=1;
    for(int i=1;i<=k;i++)
        solve(k,i);
    for(int i=1;i<=k;i++)
        p[i]=(p[i-1]+dp[k][i])%mod;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        t=fabs(t);
        if(t<=k)
            ans=(ans+p[k]-p[t-1])%mod;

    }
    ans=(ans+mod)%mod;
    cout<<ans;
    return 0;
}
