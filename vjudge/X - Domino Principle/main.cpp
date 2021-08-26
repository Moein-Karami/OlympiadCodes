///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int>pip;
const int maxn=3e5,inf=1e9;
vector <int> com;
int cnt;
pip a[maxn];
int se[4*maxn];
int ans[maxn];
map<int,int> mp;
int n;
void add(int id,int L,int R,int idx,int val)
{
    if(L+1==R)
    {
        se[id]=min(se[id],val);
        return ;
    }
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx,val);
    else
        add(2*id+1,mid,R,idx,val);
    se[id]=min(se[2*id],se[2*id+1]);

}
int say(int id,int L,int R,int l,int r)
{
    if(L==l&&r==R)
        return se[id];
    int ret=n;
    int mid=(L+R)/2;
    if(l<mid)
        ret=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        ret=min(ret,say(2*id+1,mid,R,max(l,mid),r));
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<4*maxn;i++)
        se[i]=n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].f.f>>a[i].f.s;
        a[i].s=i;
        a[i].f.s+=a[i].f.f;
        com.push_back(a[i].f.f);
        com.push_back(a[i].f.s);
    }
    sort(com.begin(),com.end());
    cnt++;
    for(int i=0;i<com.size();i++)
        if(!mp[com[i]])
            mp[com[i]]=cnt,cnt++;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        a[i].f.f=mp[a[i].f.f];
        a[i].f.s=mp[a[i].f.s];
    }
    ans[a[n-1].s]=1;
    add(1,0,cnt,a[n-1].f.f,0);
    for(int i=n-2;i>=0;i--)
    {
        int t=say(1,0,cnt,a[i].f.f,a[i].f.s);
        t=min(n-i-1,t);
        ans[a[i].s]=n-i-t;
        add(1,0,cnt,a[i].f.f,t);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
