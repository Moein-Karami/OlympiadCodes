///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
//#define int long long int
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int maxn=2e5+10;
vector <int> v[maxn];
int a[maxn];
int se[8*maxn];
int ans[maxn];
pip q[maxn];
int t[maxn];
bool bl[maxn];
bool br[maxn];
void add(int id,int L ,int R,int idx)
{
    se[id]++;
    if(L+1==R)
        return ;
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx);
    else
        add(2*id+1,mid,R,idx);
}
int say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return se[id];
    int mid=(L+R)/2;
    int ret=0;
    if(l<mid)
        ret+=say(id*2+0,L,mid,l,min(mid,r));
    if(r>mid)
        ret+=say(id*2+1,mid,R,max(mid,l),r);
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i],t[a[i]]=i;
    for(i=0;i<m;i++)
    {
        cin>>q[i].s.f>>q[i].f;
        //scanf("%lld",&q[i].s.f);
        //scanf("%lld",&q[i].f) ;
        q[i].s.s=i;
        q[i].s.f--;
        q[i].f--;
    }
    int j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n/a[i];j++)
            if(bl[j*a[i]])
                v[i].push_back(t[j*a[i]]);
        bl[a[i]]=1;
    }


    for(i=n-1;i>=0;i--)
    {
        br[a[i]]=1;
        for(j=1;j<=n/a[i];j++)
            if(br[j*a[i]])
                v[t[j*a[i]]].push_back(i);
    }
    //for(int i=0;i<n;i++)
      //  cerr<<v[i].size()<<" ";
    sort(q,q+m);
    //cerr<<endl;
    int cnt=0;
    for(i=0;i<n;i++)
    {
        //cerr<<q[cnt].f<<endl;
        for(j=0;j<v[i].size();j++)
            add(1,0,n,v[i][j]);
        while(q[cnt].f==i&&cnt<m)
        {
            //cerr<<"DONE"<<endl;
            ans[q[cnt].s.s]=say(1,0,n,q[cnt].s.f,q[cnt].f+1);
            cnt++;
        }
    }
    for(i=0;i<m;i++)
        cout<<ans[i]<<"\n";//printf("%lld\n",ans[i]);
    return 0;
}
