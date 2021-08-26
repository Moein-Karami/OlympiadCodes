///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5+5,mod=998244353;
pii a[maxn];
int fac[maxn];
int f[maxn],s[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f>>a[i].s;
        f[a[i].f]++;
        s[a[i].s]++;
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(fac[i-1]*i)%mod;
    int ans=fac[n];
    //cerr<<fac[n]<<endl;
    int tmp=1;
    for(int i=1;i<=n;i++)
        tmp=(tmp*fac[f[i]])%mod;
    ans=(ans-tmp)%mod;
    tmp=1;
    for(int i=1;i<=n;i++)
        tmp=(tmp*fac[s[i]])%mod;
    ans=(ans-tmp)%mod;
    sort(a+1,a+1+n);
    bool b=1;
    for(int i=1;i<n;i++)
        if(a[i].s>a[i+1].s)
            b=0;
    if(!b)
    {
        cout<<(ans+mod)%mod;
        return 0;
    }
    tmp=1;
    for(int i=1;i<=n;i++)
    {
        int cnt=1;
        while(a[i]==a[i+1])
            cnt++,i++;
        tmp=(tmp*fac[cnt])%mod;
    }
    ans=(ans+tmp+mod)%mod;
    cout<<ans;
}
