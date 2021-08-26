///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e5+10,inf=1e15;
int dp[maxn];
int r[maxn],l[maxn],u[maxn];
int R[maxn],L[maxn];
bool b[maxn];
pii p[maxn],tmp[maxn];
int n,m,k,q,maxr;
bool cmp(pii A,pii B)
{
    return A.s<B.s;
}
void getdata()
{
    sort(p+1,p+1+k,cmp);
    int x=-1,cnt=1;
    for(int i=1;i<=m;i++)
    {
        if(b[i])
            x=i;
        while(p[cnt].s==i)
        {
            l[cnt]=x;
            cnt++;
        }
    }
    x=-1;
    cnt=k;
    for(int i=m;i>=1;i--)
    {
        if(b[i])
            x=i;
        while(p[cnt].s==i)
        {
            r[cnt]=x;
            cnt--;
        }
    }
    for(int i=1;i<=k;i++)
        R[p[i].f]=i;
    for(int i=k;i>=1;i--)
        L[p[i].f]=i;
    for(int i=1;i<=k;i++)
    {
        tmp[i].f=p[i].f;
        tmp[i].s=i;
    }
    sort(tmp+1,tmp+1+k);
    x=maxr;
    for(int i=k;i>=1;i--)
    {
        while(tmp[i].f==tmp[i-1].f)
        {
            u[tmp[i].s]=x;
            i--;
        }
        u[tmp[i].s]=x;
        x=tmp[i].f;
    }
}
int solve(int x)
{
    if(p[x].f==maxr)
        dp[x]=0;
    if(dp[x]!=-1)
        return dp[x];
    dp[x]=inf;
    int up=u[x],left=L[up],right=R[up];
    int t;
    if(l[x]!=-1)
    {
        t=up-p[x].f+p[x].s-l[x];
        dp[x]=min(solve(right)+abs(p[left].s-l[x]),solve(left)+abs(p[right].s-l[x]));
        dp[x]+=t+p[right].s-p[left].s;
    }
    if(r[x]!=-1)
    {
        t=up-p[x].f+r[x]-p[x].s;
        int tmpdp=min(solve(right)+abs(p[left].s-r[x]),solve(left)+abs(p[right].s-r[x]));
        tmpdp+=t+p[right].s-p[left].s;
        dp[x]=min(dp[x],tmpdp);
    }
    return dp[x];
}
main()
{
    ios_base::sync_with_stdio(false);
    for(int i=0;i<maxn;i++)
    {
        dp[i]=-1;
        r[i]=-1;
        l[i]=-1;
        u[i]=-1;
        R[i]=-1;
        L[i]=-1;
    }
    cin>>n>>m>>k>>q;
    bool check=0;
    for(int i=1;i<=k;i++)
    {
        cin>>p[i].f>>p[i].s;
        if(p[i].f==1)
            check=1;
        maxr=max(maxr,p[i].f);
    }
    if(!check)
    {
        k++;
        p[k].f=1;
        p[k].s=1;
    }
    for(int i=1;i<=q;i++)
    {
        int t;
        cin>>t;
        b[t]=1;
    }
    int x=0;
    getdata();
    for(int i=1;i<=k;i++)
        if(p[i].f==1)
            x=i;
    cout<<solve(x)+p[x].s-1;
}
