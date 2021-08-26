///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
vector<int> v[maxn],une[maxn];
bool b[maxn];
vector <int> topolt,topol;
bool c[maxn];
bool mark[maxn];
int ans;
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!b[u])
        {
            b[u]=1;
            dfs(u);
        }
    }
    topolt.push_back(x);
}
void dfs2(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!c[u])
        {
            c[u]=1;
            dfs2(u);
        }
    }
}
void dfs3(int x)
{
    for(int i=0;i<une[x].size();i++)
    {
        int u=une[x][i];
        if(!mark[u])
        {
            ans++;
            mark[u]=1;
            dfs3(u);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t2].push_back(t1);
        une[t1].push_back(t2);
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            b[i]=1;
            dfs(i);
        }
    }

    for(int i=topolt.size()-1;i>=0;i--)
        topol.push_back(topolt[i]);
    c[topol[0]]=1;
    dfs2(topol[0]);
    for(int i=1;i<=n;i++)
    {
        if(!c[i])
        {
            cout<<0;
            return 0;
        }
    }
    ans++;
    mark[topol[0]]=1;
    dfs3(topol[0]);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(mark[i])
            cout<<i<<" ";
    }
    return 0;
}
