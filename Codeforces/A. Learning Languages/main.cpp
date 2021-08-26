///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
const int maxn=1e3;
vector <int> v[maxn];
vector <int> p[maxn];
vector <int> pl[maxn];
bool b[maxn];
void dfs(int x)
{
    b[x]=1;
    for(int i=0;i<p[x].size();i++)
    {
        if(!b[p[x][i]])
        {
            dfs(p[x][i]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int t;
    int a;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            cin>>a;
            v[a].push_back(i);
            pl[i].push_back(a);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            for(int q=0;q<v[i].size();q++)
            {
                if(j!=q)
                {
                    p[v[i][j]].push_back(v[i][q]);
                    p[v[i][q]].push_back(v[i][j]);
                }
            }
        }
    }
    int ans=0;
    if(pl[1].size()==0)
    {
        for(int i=2;i<=n;i++)
        {
            if(p[i].size())
            {
                p[i].push_back(1);
                ans++;
                p[1].push_back(i);
                break;
            }
        }
    }
    if(pl[1].size()==0&&p[1].size()==0&&n>1)
    {
        ans+=2;
        p[1].push_back(2);
        p[2].push_back(1);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}
