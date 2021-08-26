#include <iostream>
#define int long long int
using namespace std;
const int mod=143256989,maxn=2e5;
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
    int b=(f[y]*f[x-y])%mod;
    return (a*p(b,mod-2))%mod;
}
main()
{
    f[0]=1;
    for(int i=1;i<maxn;i++)
        f[i]=(f[i-1]*i)%mod;
    int ans=0;
    for(int i=123456;i<=123666;i++)
    {
        for(int j=123456;j<=123666;j++)
        {
            if(j>i+1)
                break;
            int t=i-j+1;
            t=c(t+j,j);
            ans=(ans+p(t,i+j))%mod;
        }
    }
    cout<<ans;
    return 0;
}
