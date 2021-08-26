///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e5;
int a[maxn];
int se[4*maxn];
int n,q;
void add(int id,int l,int r,int idx,int val)
{
    se[id]+=val;
    if(l+1==r)
        return ;
    int mid=(l+r)/2;
    if(idx<mid)
        add(id*2,l,mid,idx,val);
    else
        add(id*2+1,mid,r,idx,val);
}
int say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return se[id];
    int mid=(L+R)/2;
    int ret=0;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(l,mid),r);
    return ret;
}
int binary(int sum)
{
    int l=0,r=n,mid;
    while(l+1!=r)
    {
        mid=(l+r)/2;
        if(say(1,0,n,0,mid+1)<=sum)
            l=mid;
        else
            r=mid;
    }
    if(say(1,0,n,0,l+1)==sum)
        return l;
    else
        return -1;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        add(1,0,n,i,a[i]);
    }
    int m,t1,t2,s;
    //for(int i=1;i<=n;i++)
       // cerr<<i-1<<"  "<<say(1,0,n,0,i)<<"\n";
    for(int i=0;i<q;i++)
    {
        cin>>m;
        if(m==1)
        {
            cin>>t1>>t2;
            t1--;
            add(1,0,n,t1,t2-a[t1]);
            a[t1]=t2;
        }
        else
        {
            cin>>s;
            if(binary(s)!=-1)
                cout<<"Found "<<binary(s)+1<<"\n";
            else
                cout<<"Not Found"<<"\n";
        }
    }
    return 0;
}
