///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=7e5;
map <int,int> mp;
int a[maxn];
vector <int> com;
int parent[maxn];
pii se[4*maxn];
void add(int id,int L,int R,int idx,int val,int idc)
{
    if(se[id].f<val)
    {
        se[id].f=val;
        se[id].s=idc;
    }
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx,val,idc);
    else
        add(2*id+1,mid,R,idx,val,idc);
}
pii say(int id,int L,int R,int l,int r)
{
    if(l>=r)
        return pii(0,0);
    if(l==L&&r==R)
        return se[id];
    int mid=(L+R)/2;
    pii x,y;
    y.f=0;
    x.f=0;
    if(l<mid)
        x=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        y=say(2*id+1,mid,R,max(mid,l),r);
    if(x.f<y.f)
        swap (x,y);
    return x;
}
vector <int> ans;
main()
{
    ios_base::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        com.push_back(a[i]);
        com.push_back(a[i]+d);
        com.push_back(a[i]-d);
    }

    sort(com.begin(),com.end());
    int cnt=1;
    for(int i=0;i<=com.size();i++)
        if(!mp[com[i]])
            mp[com[i]]=cnt,cnt++;
    //d=mp[d];
    //for(int i=1;i<=n;i++)
        //a[i]=mp[a[i]];
    n++;
    for(int i=1;i<n;i++)
    {
        pii x,y;
        x.f=0;
        y.f=0;
        x=say(1,0,cnt+4,1,mp[a[i]-d]+1);
        y=say(1,0,cnt+4,mp[a[i]+d],cnt+4);
        if(y.f>x.f)
            swap(x,y);
        parent[i]=x.s;
        //cerr<<"FUCKING : "<<x.f<<endl;
        add(1,0,cnt+4,mp[a[i]],x.f+1,i);
    }
    cout<<se[1].f<<"\n";
    int idc=se[1].s;
    while(idc)
    {
        ans.push_back(idc);
        idc=parent[idc];
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
    return 0;
}
