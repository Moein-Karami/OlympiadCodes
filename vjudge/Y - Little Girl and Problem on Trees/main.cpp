///Chefer


#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5;
int se[maxn][2];
int pars[maxn];
int h[maxn];
int th[maxn];
vector <int> v[maxn];
pii baz[maxn];
int cnt;
int ans[maxn];
int a[maxn];
int DIS[maxn];
void dfs(int p,int x)
{
    cnt++;
    baz[x].f=cnt;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u!=p)
        {
            h[u]=h[x]+1;
            dfs(x,u);
            DIS[x]=max(DIS[x],DIS[u]);
        }
    }
    cnt++;
    baz[x].s=cnt;
}
void add(int id,int L,int R,int l,int r,int val,int tp)
{
    if(l>=r)
        return;
    if(l==L&&r==R)
    {
        se[id][tp]+=val;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid),val,tp);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val,tp);
}
main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1,1);
    for(int o=1;o<=q;o++)
    {
        bool tp;
        cin>>tp;
        if(!tp)
        {
            int u,m,d;
            cin>>u>>x>>d;

        }
    }
    return 0;
}
