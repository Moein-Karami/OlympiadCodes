///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e6;
int a[maxn],t[maxn];
map <int,int> mp;
int se[4*maxn][2];
int ansl[maxn],ansr[maxn];
void add(int id,int L,int R,int idx,int p)
{
    se[id][p]++;
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx,p);
    else
        add(2*id+1,mid,R,idx,p);
}
int say(int id,int L,int R,int l,int r,int p)
{
    if(L==l&&r==R)
        return se[id][p];
    int mid=(L+R)/2;
    int ret=0;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid),p);
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(mid,l),r,p);
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
    for(int i=0;i<n;i++)
        if(!mp[t[i]])
            cnt++,mp[t[i]]=i;
    for(int i=0;i<n;i++)
    {
        ansl[i]=say(1,0,n+1,mp[a[i]]+1,n+1,0);
        add(1,0,n+1,mp[a[i]],0);
    }
    for(int i=n-1;i>=0;i--)
    {
        ansr[i]=say(1,0,n+1,0,mp[a[i]],1);
        add(1,0,n+1,mp[a[i]],1);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=ansl[i]*ansr[i];
    cout<<ans;
    return 0;
}
