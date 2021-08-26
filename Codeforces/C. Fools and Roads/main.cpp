///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e5;
map <pii,int> mp;
vector <int> v[maxn];
int a[maxn];
int p[maxn][50];
int h[maxn];
int cnt[maxn];
int ans[maxn];
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!p[u][0])
        {
            h[u]=h[x]+1;
            p[u][0]=x;
            for(int j=1;j<30;j++)
                p[u][j]=p[p[u][j-1]][j-1];
            dfs(u);
        }
    }
}
int LCA(int x,int y)
{
    if(h[x]>h[y])
        swap(x,y);
    for(int i=30;i>=0;i--)
        if(h[y]-(1<<i)>=h[x])
            y=p[y][i];
    if(x==y)
        return x;
    for(int i=30;i>=0;i--)
    {
        if(p[x][i]!=p[y][i])
        {
            x=p[x][i];
            y=p[y][i];
        }
    }
    return p[x][0];
}
int solve(int x,int parent)
{
    cnt[x]+=a[x];
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u!=parent)
        {
            solve(u,x);
            cnt[x]+=cnt[u];
            ans[mp[pii(x,u)]]+=cnt[u];
        }
    }
    //cerr<<"X : "<<x<<"  "<<cnt[x]<<" "<<a[x]<<endl;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        mp[pii(t1,t2)]=i;
        mp[pii(t2,t1)]=i;
    }
    p[1][0]=1;
    dfs(1);
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int t1,t2;
        cin>>t1>>t2;
        //cerr<<"TEST : "<<t1<<" "<<t2<<" "<<LCA(t1,t2)<<endl;
        a[t1]++;
        a[t2]++;
        a[LCA(t1,t2)]-=2;
    }
    solve(1,1);
    for(int i=1;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
