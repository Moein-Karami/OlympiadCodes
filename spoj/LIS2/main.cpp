///Chefer



#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int > pii;
map <int,int> mp;
const int maxn=4e5;
pii a[maxn];
int com[3*maxn];
int se[12*maxn],lazy[12*maxn];
void pakhsh(int id)
{
    int x=2*id;
    int y=2*id+1;
    se[x]=max(lazy[id],se[x]);
    se[y]=max(lazy[id],se[y]);
    lazy[x]=max(lazy[id],lazy[x]);
    lazy[y]=max(lazy[id],lazy[y]);
    lazy[id]=0;
}
int say(int id,int L,int R,int l,int r)
{
    pakhsh(id);
    if(l==L&&r==R)
        return se[id];
    int ret=0;
    int mid=(L+R)/2;
    if(l<mid)
        ret=max(ret,say(2*id,L,mid,l,min(mid,r)));
    if(r>mid)
        ret=max(ret,say(2*id+1,mid,R,max(l,mid),r));
    return ret;
}
void add(int id,int L,int R,int l,int r,int val)
{
    pakhsh(id);

    if(l==L&&r==R)
    {
        if(val>se[id])
        {
            se[id]=val;
            lazy[id]=val;
        }
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid),val);
    if(r>mid)
        add(2*id+1,mid,R,max(mid,l),r,val);
    se[id]=max(se[2*id],se[2*id+1]);
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int cont=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f>>a[i].s;
        com[cont]=a[i].f;
        cont++;
        com[cont]=a[i].s;
        cont++;
    }
    sort(com+1,com+cont);
    int cnt=1;
    for(int i=1;i<cont;i++)
        if(!mp[com[i]])
            mp[com[i]]=cnt,cnt++;
    for(int i=1;i<=n;i++)
    {
        a[i].f=mp[a[i].f];
        a[i].s=mp[a[i].s];
    }
    for(int i=1;i<=n;i++)
    {
        int mini=min(a[i].f,a[i].s);
        int maxi=say(1,1,cont,1,mini);
        maxi++;
        add(1,1,cont,max(a[i].f,a[i].s),cont,maxi);
    }
    cout<<se[1];
    return 0;
}
