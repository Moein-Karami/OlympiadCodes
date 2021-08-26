///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5;
vector <int> v[maxn];
set <pii> se[4*maxn];
pii baz[maxn];
int h[maxn];
int cnt;
bool b[maxn];
const int inf=1e9;
void dfs(int p,int x)
{
    h[x]=h[p]+1;
    cnt++;
    baz[x].f=cnt;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=p)
            dfs(x,v[x][i]);
    cnt++;
    baz[x].s=cnt;
}
void add(int id,int L,int R,int l,int r,int val,int idc,int tp)
{

    if(L==l&&r==R)
    {
        if(tp==-1)
            se[id].erase(pii(val,idc));
        else
            se[id].insert(pii(val,idc));
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid),val,idc,tp);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val,idc,tp);
}
pii say(int id,int L,int R,int idx)
{
    set <pii>::iterator tmp;
    if(L+1==R)
    {
        if(se[id].size()==0)
            return pii(inf,inf);
        tmp=se[id].begin();
        pii x=*tmp;
        return x;
    }
    if(se[id].size()==0)
    {
        int mid=(L+R)/2;
        if(idx<mid)
            return say(2*id,L,mid,idx);
        else
            return say(2*id+1,mid,R,idx);
    }
    tmp=se[id].begin();
    pii x=*tmp;
    return x;
}
main()
{
    ios_base::sync_with_stdio(false);
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
    //for(int i=1;i<=n;i++)
      //  cerr<<"I : "<<i<<" "<<baz[i].f<<" "<<baz[i].s<<" "<<h[i]<<endl;
    for(int i=1;i<=q;i++)
    {
        int tp;
        cin>>tp;
        if(tp==0)
        {
            int t;
            cin>>t;
            if(b[t])
            {
                add(1,0,cnt,baz[t].f,baz[t].s,h[t],t,-1);
                b[t]=0;
            }
            else
            {
                b[t]=1;
                add(1,0,cnt,baz[t].f,baz[t].s,h[t],t,1);
            }
        }
        else
        {
            int v;
            cin>>v;
            int ans=say(1,0,cnt,baz[v].f).s;
            if(ans==inf)
                cout<<-1<<endl;
            else
                cout<<ans;
        }
    }
    return 0;
}
