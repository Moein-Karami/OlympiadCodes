#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6;
int se[4*maxn];
int lazy [4*maxn];
void add(int id,int L,int R,int l,int r,int val)
{
    int mid=(L+R)/2;
    se[id]+=(r-l)*val;
    se[2*id]+=(lazy[id]*(mid-L));
    se[2*id+1]+=(lazy[id]*(R-mid));
    lazy[2*id]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;
    if(l==L&&r==R)
    {
        lazy[id]+=val;
        return ;
    }
    if(l<mid)
        add(2*id,L,mid,l,min(mid,r),val);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val);
}
int say(int id,int L,int R,int l,int r)
{
    int mid=(L+R)/2;
    se[2*id]+=(lazy[id]*(mid-L));
    se[2*id+1]+=(lazy[id]*(R-mid));
    lazy[2*id]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;

    if(l==L&&r==R)
        return se[id];
    int ret=0;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(l,mid),r);
    return ret;
}
main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    int m;
    int t1,t2,t3;
    for(int i=0;i<q;i++)
    {
        cin>>m;
        if(m==1)
        {
            cin>>t1>>t2>>t3;
            t1--;
            add(1,0,n,t1,t2,t3);
        }
        else
        {
            cin>>t1>>t2;
            t1--;
            cout<<say(1,0,n,t1,t2)<<endl;
        }
    }
    return 0;
}
