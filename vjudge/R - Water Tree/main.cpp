///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e6;
pii baz[maxn];
int se[4*maxn][3];
vector <int> v[maxn];
int cnt;
void dfs(int p,int x)
{
    cnt++;
    baz[x].f=cnt;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u!=p)
            dfs(x,u);
    }
    cnt++;
    baz[x].s=cnt;
}
void add(int id,int L,int R,int l,int r,int val,int tp)
{
    if(l==L&&r==R)
    {
        se[id][tp]=val;
        return ;
    }
    int mid=(L+R)/2;
    if(tp==1)
    {
        if(l<mid)
            add(2*id,L,mid,l,min(r,mid),val,tp);
        if(r>mid)
            add(2*id+1,mid,R,max(l,mid),r,val,tp);
        return ;
    }
    se[id][tp]=val;
    if(l<mid)
        add(2*id,L,mid,l,l+1,val,tp);
    else
        add(2*id+1,mid,R,l,l+1,val,tp);
}
int say1(int id,int L,int R,int idx)
{
    if(L+1==R)
        return se[id][1];
    int ret=se[id][1];
    int mid=(L+R)/2;
    if(idx<mid)
        ret=max(ret,say1(2*id,L,mid,idx));
    else
        ret=max(ret,say1(2*id+1,mid,R,idx));
    return ret;
}
int say2(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return se[id][2];
    int mid=(L+R)/2;
    int ret=0;
    if(l<mid)
        ret=max(ret,say2(2*id,L,mid,l,min(r,mid)));
    if(r>mid)
        ret=max(ret,say2(2*id+1,mid,R,max(mid,l),r));
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1,1);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int tp;
        int u;
        cin>>tp>>u;
        if(tp==1)
        {
            add(1,1,cnt,baz[u].f,baz[u].s,i,1);
        }
        else if(tp==2)
        {
            add(1,1,cnt,baz[u].f,baz[u].f+1,i,2);
        }
        else
        {
            if(say1(1,1,cnt,baz[u].f)>say2(1,1,cnt,baz[u].f,baz[u].s))
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}
