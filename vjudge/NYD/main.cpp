///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> pip;
const int maxn=2e5+10;
pii a[maxn];
int se[8*maxn];
map <int,int> mp;
map <int,int> mp2;
vector <int>com;
pip req[maxn];
int ans[maxn];
bool b[8*maxn];
void add(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
    {
        se[id]=mp2[r]-mp2[l];
        b[id]=1;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r);
    if(!b[id])
        se[id]=se[2*id]+se[2*id+1];
}
int say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return se[id];
    if(b[id])
        return mp2[r]-mp2[l];
    int ret=0;
    int mid=(L+R)/2;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(l,mid),r);
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    n++;
    for(int i=1;i<n;i++)
    {
        cin>>a[i].f>>a[i].s;
        a[i].s+=a[i].f;
        com.push_back(a[i].f);
        com.push_back(a[i].s);
    }
    sort(com.begin(),com.end());
    int cnt=1;
    for(int i=0;i<com.size();i++)
        if(!mp[com[i]])
            mp[com[i]]=cnt,cnt++;
    for(int i=1;i<n;i++)
    {
        mp2[mp[a[i].f]]=a[i].f;
        mp2[mp[a[i].s]]=a[i].s;
        a[i].f=mp[a[i].f];
        a[i].s=mp[a[i].s];
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
        cin>>req[i].f.f>>req[i].f.s,req[i].s=i;
    sort(req+1,req+q+1);
    int c=q;
    for(int i=n-1;i>=1;i--)
    {
        add(1,1,cnt-1,a[i].f,a[i].s);
        while(req[c].f.f==i&&c)
        {
            ans[req[c].s]=mp2[a[req[c].f.s].f]-mp2[a[req[c].f.f].f]-say(1,1,cnt-1,a[req[c].f.f].f,a[req[c].f.s].f);
            c--;
        }
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
