///Chefer


#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int se[4*maxn][40];
int lazy[4*maxn][40];
int a[maxn];
void init(int id,int L,int R,int idx,int tp)
{
    se[id][tp]++;
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        init(2*id,L,mid,idx,tp);
    else
        init(2*id+1,mid,R,idx,tp);
}
void pakhsh(int id,int tp,int L,int R)
{
    lazy[id][tp]%=2;
    if(!lazy[id][tp])
        return;
    else
        lazy[id][tp]=0;
    int x=2*id,y=2*id+1,mid=(L+R)/2;
    lazy[x][tp]++;
    lazy[y][tp]++;
    se[x][tp]=mid-L-se[x][tp];
    se[y][tp]=R-mid-se[y][tp];
}
void chenge(int id,int L,int R,int l,int r,int tp)
{
    pakhsh(id,tp,L,R);
    if(l==L&&r==R)
    {
        lazy[id][tp]++;
        se[id][tp]=R-L-se[id][tp];
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        chenge(2*id,L,mid,l,min(r,mid),tp);
    if(r>mid)
        chenge(2*id+1,mid,R,max(l,mid),r,tp);
    se[id][tp]=se[2*id][tp]+se[2*id+1][tp];
}
int say(int id,int L,int R,int l,int r,int tp)
{
    pakhsh(id,tp,L,R);
    if(l==L&&r==R)
        return se[id][tp];
    int ret=0;
    int mid=(L+R)/2;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid),tp);
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(l,mid),r,tp);
    return ret;
}
main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=30;j++)
        {
            if(a[i]&(1LL<<j))
                init(1,0,n,i,j);
        }
    }
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int tp;
        cin>>tp;
        if(tp==2)
        {
            int l,r,x;
            cin>>l>>r>>x;
            l--;
            for(int i=0;i<31;i++)
            {
                if((1LL<<i)&x)
                    chenge(1,0,n,l,r,i);
            }
        }
        else
        {
            int l,r;
            cin>>l>>r;
            l--;
            long long int  ans=0;
            for(int i=0;i<31;i++)
            {
                long long int  t=say(1,0,n,l,r,i);
                ans+=t*(1LL<<i);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
