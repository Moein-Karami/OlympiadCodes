#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
const int mod=1e9+7,del=10559;
int po(int x,int y)
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
int f(int x)
{
    int ret=1;
    if(x>=mod)
    {
        for(int i=1;i<mod;i++)
            ret=(ret*i)%mod;
        int t=x/mod;
        ret=po(ret,t);
        t=x%mod;
        for(int i=1;i<=t;i++)
            ret=(ret*i)%mod;
        return ret;
    }
    for(int i=1;i<=x;i++)
        ret=(ret*i)%mod;
    return ret;
}
int c(int x,int y)
{
    int s=f(x),m1=f(y),m2=f(x-y);
    int m=(m1*m2)%mod;
    return (s*po(m,mod-2))%mod;
}
main()
{
    int n,t,k;
    cin>>n>>t>>k;
    //cerr<<"BARG : "<<(1LL<<n)<<" "<<t<<"   "<<c((1LL<<n),t)<<endl;
    //cerr<<"TAGHSIM : "<<k<<"  "<<c((1LL<<n)-t,k-t+1)<<endl;
    int x=(c((1LL<<n),t)*c((1LL<<n)-t,k-t+1))%mod;
    cout<<x<<"  "<<x%del;
    return 0;
}
