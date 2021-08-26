#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=110,mod=10753;
int c[maxn][maxn],f[maxn];
int dp[maxn][maxn];
int po[maxn];
int p(int x,int y)
{
    int ret=1;
    //if(x<0)
      //  x=-x;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
int solve(int x,int y)
{
    //cerr<<"X & Y : "<<x<<" "<<y<<endl;
    //getchar();
    if(x==0)
        return 1;
    if(y==0)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    int &ret=dp[x][y];
    ret=solve(x,y-1);
    for(int i=1;i*y<=x;i++)
    {
        int t=1;
        for(int j=1;j<=i;j++)
            t=(t*c[x-j*y+y][y])%mod;
        //cerr<<"X & Y & I : "<<x<<" "<<y<<" "<<i<<" "<<((p(f[y-1],i)*t*p(f[i],mod-2))%mod)*p(po[y]-y,i)*solve(x-i*y,y-1)<<endl;
        ret=(ret+((p(f[y-1],i)*t*p(f[i],mod-2))%mod)*p(po[y]-y,i)*solve(x-i*y,y-1))%mod;
    }
    return ret;
}
main()
{
    f[0]=1;
    po[0]=1;
    for(int i=1;i<maxn;i++)
        f[i]=(f[i-1]*i)%mod,po[i]=(2*po[i-1])%mod;
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    int n;
    cin>>n;
    cout<<solve(n,n);
    return 0;
}
