#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10513;
int f[21];
int dp[20];
int sum[20];
int pars[20];
int base;
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
    f[0]=1;
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]*i,pars[i]=pars[i-1]+f[i];
    base=f[n]+3;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            dp[i]=(dp[i]+((dp[i-1]+(j-1)*f[i-1]*(((p(base,f[i-1])-1)*p(base-1,mod-2))%mod))%mod)*p(base,(n-j)*f[i-1]))%mod;
        //cerr<<"I : "<<i<<" "<<dp[i]<<endl;
    }
    sum[1]=1;
    for(int i=2;i<=n;i++)
        sum[i]=(sum[i-1]*p(base,f[i])+dp[i]+(pars[i-1]*(1-p(base,f[i]))*p(1-base,mod-2)))%mod;
    //cerr<<sum[n]<<endl;
    cout<<((sum[n-1]+(dp[n]-sum[n-1]*p(base,f[n]-pars[n-1]))*p(base,pars[n-1]))%mod+mod)%mod;


    return 0;
}
