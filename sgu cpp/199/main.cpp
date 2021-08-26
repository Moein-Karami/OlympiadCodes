///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int maxn=1e5+5;
int inf=1e9;
pip t[maxn];
pii a[maxn];
pii dp1[maxn];
pii dp2[maxn];
int son[maxn];
int binary (int l,int r, int x)
{
    if(l+1==r)
        return l;
    int mid=(l+r)/2;
    if(dp1[mid].f<x)
        return binary(mid,r,x);
    else
        return binary(l,mid,x);
}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].f>>t[i].s.f;
        t[i].s.s=i;
    }
    sort(t,t+n+1);
    for(int i=1;i<=n;i++)
    {
        a[i].f=t[i].s.f;
        a[i].s=t[i].s.s;
    }
    for(int i=1;i<maxn;i++)
        dp1[i].f=inf,dp2[i].f=inf;
    for(int i=1;i<=n;i++)
    {
        vector <int> v;
        do
        {
            int p=binary(0,n,a[i].f);
            if(dp1[p+1].f>a[i].f)
            {
                if(dp2[p+1].f>a[i].f)
                {
                    dp2[p+1].f=a[i].f;
                    dp2[p+1].s=a[i].s;
                    son[a[i].s]=dp2[p].s;
                    v.push_back(p+1);
                }
            }
            i++;
        }while(t[i].f==t[i-1].f);
        i--;
        for(int j=0;j<v.size();j++)
        {
            dp1[v[j]].f=dp2[v[j]].f;
            dp1[v[j]].s=dp2[v[j]].s;
        }
    }
    int x;
    for(int i=n;i>=0;i--)
    {
        if(dp1[i].f<inf)
        {
            x=dp1[i].s;
            cout<<i<<endl;
            break ;
        }
    }
    while(x)
    {
        cout<<x<<" ";
        x=son[x];
    }
    return 0;
}
