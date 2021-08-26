///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e7+7;
int se[4*maxn];
int a[maxn];
void add(int id,int L,int R,int val,int idx)
{
    if(L+1==R)
    {
        se[id]+=val;
        return ;
    }
    se[id]+=val;
    int mid=(L+R)/2;
    if(idx<mid)
        add(id*2,L,mid,val,idx);
    else
        add(id*2+1,mid,R,val,idx);
}
int say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return se[id];
    int mid=(L+R)/2;
    int ret=0;
    //cerr<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(mid,r));
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(l,mid),r);
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int n,ans=0,maxi=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],maxi=max(a[i],maxi);
        memset(se,0,sizeof se);
        for(int i=1;i<=n;i++)
        {
            ans+=say(1,0,maxi+1,a[i],maxi+1);
            //cerr<<endl;
            add(1,0,maxi+1,1,a[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
