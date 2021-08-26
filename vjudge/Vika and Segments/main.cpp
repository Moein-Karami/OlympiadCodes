///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5;
int handle[4*maxn],LD[4*maxn],LP[4*maxn],ANS[4*maxn];
pii a[maxn];
int maxi[maxn];
int n;
void segment(int id,int L,int R,int l,int r,vector <int> v)
{
    if(l==L&&r==R)
    {
        v.push_back(id);
        return ;
    }
    int mid(L+R/2);
    if(l<mid)
        segment(2*id,L,mid,l,min(r,mid),v);
    if(r>mid)
        segment(2*id+1,mid,R,max(l,mid),r,v);
}
int binary(vector <int> v,int h)
{
    int l=0,r=v.size(),mid;
    while(l+1==r)
    {
        mid=(l+r)/2;
        if(h>=LD[mid])
            l=mid;
        else
            r=mid;
    }
    if(r==v.size())
        return -1;
    else
        return r;
}
int say(int id,int L ,int R,int l,int r)
{
    if(L+1==R)
        return 0;
    vector <int> v;
    segment(id,L,R,l,r,v);
    int ret=0;
    ret+=ANS[v[0]];
    int s=v.size();
    int h=handle[v[0]];
    int x=binary(v,h);
    if(x==-1)
        return ret;
    ret+=min(a[LD[x]].f-h,a[LD[x]].f-LP[x])+say(id,L,R,LD[x],r);
    return ret;
}
void solve(int id,int L,int R)
{
    if(L>=R)
        return ;
    if(L+1==R)
    {
        handle[id]=a[id].f+a[id].s;
        LD[id]=0;
        LP[id]=0;
        ANS[id]=0;
        return ;
    }
    int mid=(L+R)/2;
    solve(2*id,L,mid);
    solve(2*id+1,mid,R);
    int x=2*id,y=2*id+1;
    if(LD[x])
        LD[id]=LD[x];
    if(LP[x])
        LP[id]=LP[x];
    handle[id]=max(handle[x],handle[y]);
    int ans=0;
    int h=handle[x];
    int f=0;
    if(LD[id]==0)
    {
        for(int i=mid;i<R;i++)
        {
            h=max(h,maxi[i]);
            if(h<a[i+1].f&&i<R-1)
            {
                LD[id]=LD[i+1];
                LP[id]=h;
                f=a[LD[id]].f-LP[id];
            }
        }
    }
    ans+=ANS[x];
    ans+=f+say(1,0,n,LD[id],R);
    ANS[id]=ans;
}
main()
{

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].f>>a[i].s,maxi[i]=a[i].f+a[i].s;
    solve(1,0,n);
    int m;
    cin>>m;
    int t1,t2;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        cout<<say(1,0,n,t1,t2);

    }
    return 0;
}
