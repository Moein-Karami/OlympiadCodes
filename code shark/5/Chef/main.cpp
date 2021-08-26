#include <bits/stdc++.h>
#define int long long int
#define double long double
using namespace std;
const int mod=11161,maxn=2e7;
double f[maxn];
main()
{
    double n;
    cin>>n;
    f[1]=1;
    //cout<<fixed<<setprecision(4);
    for(int i=2;i<=n;i++)
    {
        f[i]=((n-i+1)*f[i-1]+n)/(n-i+1);
        //cerr<<"I : "<<f[i]<<endl;
    }
    double ans=0;
    for(int i=1;i<=n;i++)
        ans+=f[i];
    ///cout<<ans<<endl;
    ans*=1000.0;
    ///cout<<ans<<endl;
    int t=ans;
    t%=mod;
    cout<<t<<endl;
    int ret=1;
    for(int i=1;i<=5;i++)
        ret=(ret*t)%mod;
    cout<<ret;
    return 0;
}
