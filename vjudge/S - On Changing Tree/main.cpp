///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
const int maxn=7e5mod=1e9+7;
int baz[maxn];
int se[4*maxn];
int a[maxn];
vector <int> v[maxn];
int cnt;
pii baz[maxn];
void dfs(int p,int x)
{
    cnt++;
    baz[x].f=cnt;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u!=p)
            dfs(x,u);
    }
    cnt++;
    baz[x].s=cnt;
}
main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int t;
        cin>>t;
        v[t].push_back(i);
        v[i].push_back(t);
    }
    dfs(1,1);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int tp;
        cin>>tp;
        if(tp==1)
        {
            int u,x,k;
            cin>>u>>x>>k;
            add()
        }
    }
    return 0;
}
