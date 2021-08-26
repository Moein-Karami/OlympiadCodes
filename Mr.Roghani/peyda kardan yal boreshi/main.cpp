#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int n;
int m;
const int maxn=1e6;
vector <pii> v[maxn+10];
int h[maxn+10];
int dp[maxn+10];
bool bv[maxn+10];
bool be[maxn+10];
void dfs(int p,int x)
{

    dp[x]=1e9;
    for(int i=0;i<v[x].size();i++)
    {
        if(!bv[v[x][i].f])
        {
            bv[v[x][i].f]=1;
            h[v[x][i].f]=h[x]+1;
            dfs(x,v[x][i].f);
            dp[x]=min(dp[x],dp[v[x][i].f]);
        }
        else if(v[x][i].f!=p)
            dp[x]=min(dp[x],h[v[x][i].f]);
        if(dp[v[x][i].f]<=h[x])
            be[v[x][i].s]=1;
    }

}
main()
{
    cin>>n>>m;
    int t1,t2;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        v[t1].push_back(pii(t2,i));
        v[t2].push_back(pii(t1,i));
    }
    bv[1]=1;
    dfs(1,1);
    for(int i=1;i<=m;i++)
        if(be[i])
            cout<<i<<endl;
    return 0;
}
