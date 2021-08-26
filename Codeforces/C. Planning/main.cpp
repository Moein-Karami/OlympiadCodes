///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
#define rand() rand()*rand()
using namespace std;
typedef pair<int ,int > pii;
const int maxn=5e5;
set <pii> s;
int a[maxn];
int ans[maxn];
int se[10*maxn];
const int inf=1e9;
int  cost;
void rem(int id,int L,int R,int idx)
{
    if(L+1==R)
    {
        se[id]=inf;
        return ;
    }
    int mid=(L+R)/2;
    if(idx<mid)
        rem(2*id,L,mid,idx);
    else
        rem(2*id+1,mid,R,idx);
    se[id]=min(se[2*id],se[2*id+1]);
}
void init(int id,int L,int R)
{
    if(L+1==R)
    {
        se[id]=L;
        return ;
    }
    int mid=(L+R)/2;
    init(2*id,L,mid);
    init(2*id+1,mid,R);
    se[id]=min(se[2*id],se[2*id+1]);
}
int say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return se[id];
    int ret=inf;
    int mid=(L+R)/2;
    if(l<mid)
        ret=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        ret=min(ret,say(2*id+1,mid,R,max(mid,l),r));
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    //n=rand()%300000;
    //k=rand()%300000;
    init(1,1,k+n+1);
    cerr<<n<<" "<<k<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //a[i]=rand()%10000000;
        s.insert(pii(-a[i],i));
    }
    set<pii> ::iterator x;
    pii tmp;
    int t;
    for(int i=1;i<=n;i++)
    {
        //cerr<<i<<endl;
        x=s.begin();
        //cerr<<i<<endl;
        tmp=*x;
        //cerr<<i<<endl;
        s.erase(*x);
        //cerr<<i<<endl;
        tmp.f=-tmp.f;
        //cerr<<i<<endl;
        t=say(1,1,k+n+1,max(k+1,tmp.s),k+1+n);
        ans[tmp.s]=t;
        cost+=(t-tmp.s)*tmp.f;
        rem(1,1,k+1+n,t);
        //cerr<<i<<endl;
    }
    cout<<cost<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
