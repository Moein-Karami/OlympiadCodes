///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e5;
int se[4*maxn][21];
int a[maxn];
void add(int id,int L,int R,int idx,int val,int tp)
{
    se[id][tp]+=val;
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx,val,tp);
    else
        add(2*id+1,mid,R,idx,val,tp);
       // cerr<<"Id & L & R : "<<se[id][tp]<<" "<<L<<" "<<R<<endl;
}
int say(int id,int L,int R,int l,int r,int tp)
{
    if(l==L&&r==R)
        return se[id][tp];
    int mid=(L+R)/2;
    int ret=0;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid),tp);
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(mid,l),r,tp);
        //cerr<<"Id & L & R : "<<se[id][tp]<<" "<<L<<" "<<R<<endl;
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int x=say(1,0,n+1,0,a[i],j);
            if(j==0)
                x=1;
            add(1,0,n+1,a[i],x,j+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=say(1,0,n+1,i,i+1,k+1);
    cout<<ans<<endl;
    return 0;
}
