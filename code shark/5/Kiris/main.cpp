#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e4+4,mod=10753;
int dp[maxn][maxn];
int ans[maxn];
int f[maxn];
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
int c(int x,int y)
{
    int a=f[x];
    int b=f[y]*f[x-y];
    b%=mod;
    return (x*p(b,mod-2))%mod;
}
int solve(int x,int y)
{
    int &ret=dp[x][y];
    if(y>x)
        return 0;
    if(x==0)
        return 1;
    if(ret)
        return ret;
    for(int i=1;i<=x-y+1;i++)
    {
        ret=(ret+solve(x-i,y-1)*c(x,i)*ans[i]*p(2,i*(x-i)))%mod;
    }
    cout<<"X&Y : "<<x<<" "<<y<<" "<<ret<<endl;
    return ret;
}
main()
{
    int n;
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++)
        f[i]=(f[i-1]*i)%mod;
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=p(2,i*i);
        for(int j=2;j<=i;j++)
            ans[i]=(ans[i]-solve(i,j))%mod;
        ans[i]+=mod;
        ans[i]%=mod;
    }
    cout<<ans[n];
    return 0;
}
