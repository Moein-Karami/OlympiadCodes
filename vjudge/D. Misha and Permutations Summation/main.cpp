///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5;
int a[maxn],b[maxn],mabna[maxn];
int se[4*maxn][3];
void add(int id,int L,int R,int idx,int tp)
{
    se[id][tp]++;
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx,tp);
    else
        add(2*id+1,mid,R,idx,tp);
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
        ret+=say(2*id+1,mid,R,max(l,mid),r,tp);
    return ret;
}
main()
{
    int n;
    cin>>n;
    for(int i=n-1;i>=0;i--)
        cin>>a[i];
    for(int i=n-1;i>=0;i--)
        cin>>b[i];
    for(int i=n-1;i>=0;i--)
    {
        add(1,0,n,a[i],0);
        add(1,0,n,b[i],1);
        a[i]-=say(1,0,n,0,a[i],0);
        b[i]-=say(1,0,n,0,b[i],1);
        mabna[i]=a[i]+b[i];
        //cerr<<"mabna : "<<mabna[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        mabna[i+1]+=mabna[i]/(i+1);
        mabna[i]%=(i+1);
    }
    for(int i=n-1;i>=0;i--)
    {
        int l=0,r=n;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            if(say(1,0,n,0,mid,2)+mabna[i]>=mid)
                l=mid;
            else
                r=mid;
        }
        add(1,0,n,l,2);
        cout<<l<<" ";
    }
    return 0;
}
