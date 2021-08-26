#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int mod=10559,maxn=1e6+6;
int p[maxn];
int s[maxn];
int a[maxn];
set<pii> se;
main()
{
    int n,k;
    cin>>n>>k;
    for(int i=2;i<maxn;i++)
        if(!p[i])
            for(int j=i;j<maxn;j+=i)
                p[j]=i;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(i==p[i])
            cnt++;
    }
    cout<<cnt<<endl;
    for(int i=2;i<=n;i++)
    {
        int t=i,mini=maxn;
        while(t>1)
        {
            mini=min(mini,p[t]);
            t/=p[t];
        }
        s[i/mini]++;
    }
    for(int i=2;i<=n;i++)
        if(p[i]==i)
            se.insert(pii(s[i],i));
    int h=0;
    set<pii>::iterator it;
    int x;
    while(se.size())
    {
        it=se.begin();
        x=(*it).f;
        se.erase(it);
        h+=x;
        a[h]++;
    }
    int ans=0;
    int last=0;
    x=0;
    for(int i=0;i<=k;i++)
    {
        if(a[i])
            last=i;
        x+=a[i];
        ans=(ans+((x*last)%mod)*((x*last)%mod))%mod;
    }
    cout<<ans;
    return 0;
}
