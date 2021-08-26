#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=12299395,mod=10607;
int f[maxn],p[maxn];
vector<int> v[maxn];
main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        if(v[i].size()==0)
            for(int j=i;j<=n;j+=i)
                v[j].push_back(i),p[j]=i;
    f[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(i%10000==0)
        {
            cerr<<i<<endl;
        }
        for(int j=0;j<(1<<(v[i].size()));j++)
        {
            int t=1;
            for(int k=0;k<v[i].size();k++)
            {
                if((1<<k)&(j))
                    t*=v[i][k];
            }
            if(__builtin_popcount(j)%2==0)
                f[i]+=(i-1)/t;
            else
                f[i]-=(i-1)/t;
        }
    }
    int x;
    cin>>x;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int t=1;
        int cnt=1;
        int y=i;
        while(y!=1)
        {
            if(p[y]==p[y/p[y]])
                cnt++;
            else
            {
                cnt++;
                t*=cnt;
                cnt=1;
            }
            y/=p[y];
        }
        //cerr<<"I : "<<i<<" "<<t<<endl;
        //getchar();
        if(t!=x)
            continue;
        //cerr<<"I : "<<i<<endl;
        ans++;
        for(int j=2;j*i<n;j++)
            ans+=2*f[j];
    }
    cout<<ans<<" "<<ans%mod;
    return 0;
}
