///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e6;
int a[maxn],t[maxn];
int se[4*maxn];
int tmpl[maxn],tmpr[maxn];
int counterr[maxn],counterl[maxn];
map <int,int> mp;
void add(int id,int L, int R,int idx,int val)
{
    se[id]+=val;
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        add(id*2,L,mid,idx,val);
    else
        add(id*2+1,mid,R,idx,val);
}
int say(int id,int L,int R,int l,int r)
{
    //cerr<<L<<" "<<R<<endl<<l<<" "<<r<<endl;
    if(l==L&&r==R)
    {
        //cerr<<se[id]<<" "<<id<<endl;
        return se[id];
    }
    int mid=(L+R)/2;
    int ret=0;
    //cerr<<L<<" "<<R<<endl<<l<<" "<<r<<endl<<endl;
    if(l<mid)
        ret+=say(id*2,L,mid,l,min(r,mid));
    if(r>mid)
        ret+=say(id*2+1,mid,R,max(mid,l),r);
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],t[i]=a[i];
    sort(t,t+n);
    int cnt=0;
    ///comperese
    for(int i=0;i<n;i++)
        if(!mp[t[i]])
            cnt++,mp[t[i]]=cnt;
    ///

    /// coutner left
    for(int i=0;i<n;i++)
    {
        tmpl[i]=counterl[mp[a[i]]];
        counterl[mp[a[i]]]++;
    }
    ///

    ///counter right
    for(int i=n-1;i>=0;i--)
    {
        tmpr[i]=counterr[mp[a[i]]];
        add(1,0,n+1,tmpr[i],1);
        counterr[mp[a[i]]]++;
    }
    ///
    int ans=0;
    for(int i=0;i<n;i++)
    {
        add(1,0,n+1,tmpr[i],-1);
        ans+=say(1,0,n+1,0,tmpl[i]);
        //cerr<<say(1,0,n+1,0,tmpl[i])<<" ";
    }
    cout<<ans;
    return 0;
}
