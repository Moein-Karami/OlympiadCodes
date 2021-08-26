#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6,mod=12263;
int p[maxn],f[maxn];
main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        if(!p[i])
            for(int j=i;j<=n;j+=i)
                p[j]=i;
    for(int i=1;i<=n;i++)
    {
        vector<int> v;
        int t=i;
        while(t>1)
        {
            if(p[t]!=p[t/p[t]])
                v.push_back(p[t]);
            t/=p[t];
        }
        f[i]=n;
        for(int j=1;j<(1<<v.size());j++)
        {
            t=1;
            for(int k=0;k<v.size();k++)
            {
                if((1<<k)&j)
                    t*=v[k];
            }
            t=n/t;
            if(__builtin_popcount(j)%2==1)
                f[i]-=t;
            else
                f[i]+=t;
        }
    }
    int x=0,t=0;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        ans=(ans+f[i]*x)%mod;
        t+=f[i];
        x+=t;
        t%=mod;
        x%=mod;
    }
    cout<<(2*ans)%mod;
    return 0;
}
