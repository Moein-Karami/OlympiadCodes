#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10631,maxn=14000;
int ans[maxn],rev[maxn];
int sum[maxn],po[maxn];
int p(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return ret;
}
main()
{
    int n;
    cin>>n;
    po[0]=1;
    for(int i=1;i<maxn;i++)
        po[i]=(po[i-1]*n)%mod;
    sum[0]=1;
    for(int i=1;i<=n;i++)
        sum[i]=(((po[i]*(po[i]+1))%mod)*p(2,mod-2))%mod;
    ans[0]=1;
    rev[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=((j-1)*po[i-1])%mod;
            int y=((n-j)*po[i-1])%mod;
            ans[i]=(ans[i]+rev[i-1]+po[i-1]*x*y+x*sum[i-1]+y*sum[i-1])%mod;
            y=x;
            rev[i]=(rev[i]+ans[i-1]+po[i-1]*x*y+x*sum[i-1]+y*sum[i-1])%mod;
        }
        //cerr<<"I : "<<i<<" "<<ans[i]<<" "<<rev[i]<<endl;
    }
    cout<<ans[n];
    return 0;
}
