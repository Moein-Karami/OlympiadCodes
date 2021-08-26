///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5,inf=1e9;
vector <int> v[maxn];
bool b[maxn];
int bckedg[maxn];
int h[maxn];
int start[maxn],finish[maxn];
int parent[maxn][32];
bool mark[maxn];
int sums[maxn],sumf[maxn];
int cnt;
int moal[maxn];
map <pii,int > mp;
int LCA(int x,int y)
{
    if(h[x]>h[y])
        swap(x,y);
    for(int i=30;i>=0;i--)
        if(h[y]-(1LL<<i)>=h[x])
            y=parent[y][i];
    if(x==y)
        return x;
    for(int i=30;i>=0;i--)
    {
        if(parent[x][i]!=parent[y][i])
        {
            x=parent[x][i];
            y=parent[y][i];
        }
    }
    return parent[x][0];
}
void dfs(int p,int x)
{
    //cerr<<x<<endl;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!b[u])
        {
            parent[u][0]=x;
            for(int j=1;j<=30;j++)
                parent[u][j]=parent[parent[u][j-1]][j-1];
            h[u]=h[x]+1;
            b[u]=1;
            dfs(x,u);
            bckedg[x]=min(bckedg[x],bckedg[u]);
        }
        else if(u!=p)
            bckedg[x]=min(bckedg[x],h[u]);
    }
}
void solve(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!mark[u])
        {
            mark[u]=1;
            solve(u);
            sumf[x]+=sumf[u];
            sums[x]+=sums[u];
            if(sumf[u]&&sums[u]&&bckedg[u]>h[x]&&mp[pii(x,u)]<=1)
            {
                //cerr<<"X & U : "<<x<<" "<<u<<endl;
                cout<<"No";
                exit(0);
            }
        }
    }
    sumf[x]+=finish[x];
    sums[x]+=start[x];
}
void khoosh(int x,int tp)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!moal[u])
        {
            moal[u]=tp;
            khoosh(u,tp);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        bckedg[i]=inf;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        mp[pii(t1,t2)]++;
        mp[pii(t2,t1)]++;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for(int i=1;i<=n;i++)
    {
        if(!moal[i])
        {
            cnt++;
            moal[i]=cnt;
            khoosh(i,cnt);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            b[i]=i;
            dfs(i,1);
        }
    }
    for(int i=1;i<=k;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        start[t1]++;
        finish[t2]++;
        if(moal[t1]!=moal[t2])
        {
            cout<<"No";
            return 0;
        }
        int lca=LCA(t1,t2);
        start[lca]--;
        finish[lca]--;
    }
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            mark[1]=1;
            solve(1);
        }
    }
    cout<<"Yes";
    return 0;
}
