///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=4e5,maxm=1e6+10;
vector <pii> v[maxm];
int t[maxn];
pii baz[maxn];
int ans[maxn];
int cnt;
int se[4*maxm];
void add(int id,int L,int R,int idx)
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
    //cerr<<"ID & L & R & VAL : " <<id<<" "<<L<<" "<<R<<" "<<se[id]<<endl;
    if(l==L&&r==R)
        return se[id];
    int ret=0;
    int mid=(L+R)/2;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(mid,l),r);
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>baz[i].s>>baz[i].f;
    sort(baz+1,baz+n+1);
    for(int o=1;o<=q;o++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
            cin>>t[j];
        sort(t,t+m);
        v[t[0]-1].push_back(pii(1,o));
        v[1000000].push_back(pii(t[m-1]+1,o));
        for(int i=1;i<m;i++)
        {
            if(t[i]-1>t[i-1]+1)
                v[t[i]-1].push_back(pii(t[i-1]+1,o));
        }
    }
    cnt=1;
    for(int i=1;i<maxm;i++)
    {
        while(baz[cnt].f==i)
        {
            add(1,1,maxm,baz[cnt].s);
            cnt++;
        }
        if(v[i].size())
        //cerr<<endl<<"I : "<<i<<endl;
        for(int j=0;j<v[i].size();j++)
        {
            //cerr<<v[i][j].f<<" ";
            ans[v[i][j].s]+=say(1,1,maxm,v[i][j].f,i+1);
        }
    }//cerr<<endl;
    for(int i=1;i<=q;i++)
        cout<<n-ans[i]<<"\n";
    return 0;
}
