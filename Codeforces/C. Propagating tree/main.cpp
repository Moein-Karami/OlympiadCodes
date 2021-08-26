///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int cnt;
const int maxn=2e6;
int se[4*maxn][2];
int a[maxn];
int p[maxn];
int h[maxn];
pii baz[maxn];
vector <int> v[maxn];
void dfs(int x)
{
    cnt++;
    baz[x].f=cnt;
    for(int i=0;i<v[x].size();i++)
    {
        if(!p[v[x][i]])
        {
            h[v[x][i]]=h[x]+1;
            p[v[x][i]]=x;
            dfs(v[x][i]);
        }

    }

    cnt++;
    baz[x].s=cnt;
}
int say(int id,int L,int R,int idx,int tp)
{
    int mid=(L+R)/2;
    int ret=0;
    ret+=se[id][tp];
    if(L+1==R)
        return ret;
    if(idx<mid)
        ret+=say(2*id,L,mid,idx,tp);
    else
        ret+=say(2*id+1,mid,R,idx,tp);
    return ret;
}
void add(int id,int L,int R,int l,int r,int val,int tp)
{
    if(l==L&&r==R)
    {
        se[id][tp]+=val;
        return ;
    }
    //cerr<<"L & R & l & r : "<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(mid,r),val,tp);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val,tp);
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t1,t2;
    for(int i=1;i<n;i++)
    {
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    p[1]=1;
    dfs(1);
    n++;
    int tp,val;
    for(int o=1;o<=q;o++)
    {

        cin>>tp;
        if(tp==1)
        {
            cin>>t1>>val;
            add(1,1,cnt+1,baz[t1].f,baz[t1].s,val,h[t1]%2);
            for(int i=0;i<v[t1].size();i++)
                if(p[t1]!=v[t1][i])
                    add(1,1,cnt+1,baz[v[t1][i]].f,baz[v[t1][i]].s,-val,1-(h[t1]%2));
        }
        else
        {
            cin>>t1;
            cout<<a[t1]+say(1,1,cnt+1,baz[t1].f,h[t1]%2)<<"\n";
        }
    }
    return 0;
}
