#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6;
int p[maxn];
int mod=12263;
main()
{
    for(int i=2;i<maxn;i++)
        if(!p[i])
            for(int j=i;j<maxn;j+=i)
                p[j]=i;
    int ans=0;
    int n;
    cin>>n;
    for(int i=3;i<=n;i+=2)
    {
        int t=i;
        vector<int> v;
        //cerr<<"I : "<<i<<endl;
        while(t>1)
        {
            if(p[t]!=p[t/p[t]])
                v.push_back(p[t]);
            t/=p[t];
        }
        int x=i/2;
        for(int j=1;j<(1<<v.size());j++)
        {
            int tmp=1;
            for(int k=0;k<v.size();k++)
            {
                if((1<<k)&(j))
                    tmp*=v[k];
            }
            //cerr<<"I & J & TMP : "<<i<<" "<<j<<" "<<tmp<<endl;
            tmp=(i-1)/tmp;
            tmp=tmp/2+(tmp%2);
            if(__builtin_popcount(j)%2==1)
                x-=tmp;
            else
                x+=tmp;
        }
        //cerr<<"I : "<<i<<" "<<x<<endl;
        //cerr<<"I : "<<i<<" "<<x<<endl;
        ans+=x*(n/i);
    }
    cout<<ans<<" "<<ans%mod;
    return 0;
}
