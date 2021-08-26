#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10753;
const int maxn=1e7+70;
int p[maxn];
int f[maxn];
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
main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        if(!p[i])
            for(int j=i;j<=n;j+=i)
                p[j]=i;
    f[1]=0;
    for(int i=2;i<=n;i++)
    {
        //cerr<<"I : "<<i<<endl;
        vector<int> v;
        int t=i;
        while(t>1)
        {
            if(p[t]!=p[t/p[t]])
                v.push_back(p[t]);
            t/=p[t];
        }
        f[i]=i;
        for(int j=1;j<(1<<v.size());j++)
        {
            int t=1;
            for(int k=0;k<v.size();k++)
            {
                if(j&(1<<k))
                    t*=v[k];
            }
            //cerr<<t<<endl;
            t=i/t;
            if(__builtin_popcount(j)%2==1)
                f[i]-=t;
            else
                f[i]+=t;
        }
        //cerr<<"I : "<<i<<" "<<f[i]<<endl;
        //getchar();
    }
    int ans=1;
    for(int i=1;i<=n;i++)
        ans=(ans*po(2,2*i))%mod;
    //cerr<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=n/i;j++)
        {
            ans=(ans*po(2,i*4*f[j]))%mod;
        }
        //cerr<<"I : "<<i<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
