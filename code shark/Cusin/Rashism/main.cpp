#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7;
int p[1000000];
int f[1000000];
int po(int x,int y)
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
int c(int x,int y)
{
    x%=mod;
    y%=mod;
    return (po(y,mod-2)*x)%mod;
}
main()
{
    p[0]=1;
    f[0]=1;
    for(int i=1;i<1000000;i++)
        p[i]=(2*p[i-1])%mod,f[i]=(f[i-1]*i)%mod;
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n/2;i++)
    {
        int t=i-1;
        int x=n-i-1;
        int tmp=c(f[x],f[t]*f[x-t]);
        //cerr<<"TMP : "<<tmp<<endl;
        x=(n*tmp)%mod;
        x=(x*i)%mod;
        x=(x*p[i])%mod;
        x=(x*3)%mod;
        ans=(ans+x)%mod;
    }
    cout<<ans%12799;
    return 0;
}
