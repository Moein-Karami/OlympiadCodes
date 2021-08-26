///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e3+3;
vector <int> v[maxn];
vector <int> une[maxn];
vector <int> topolt,topol;
bool b[maxn];
bool mark[maxn];
int ans;
int n;
void clean()
{
    for(int i=0;i<maxn;i++)
        mark[i]=0,b[i]=0;
    topol.clear();
    topolt.clear();
    ans=0;
    for(int i=0;i<maxn;i++)
        v[i].clear(),une[i].clear();
}
void dfs(int x)
{
    b[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!b[u])
            dfs(u);
    }
    topolt.push_back(x);
}
void dfs2(int x)
{
    mark[x]=1;
    for(int i=0;i<une[x].size();i++)
        if(!mark[une[x][i]])
            dfs2(une[x][i]);
}
main()
{
    ios_base::sync_with_stdio(false);
    int q;
    char c;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        cin>>n;
        clean();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>c;
                if(c=='Y')
                {
                    v[i].push_back(j);
                    une[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++)
            if(!b[i])
                dfs(i);
        for(int i=topolt.size()-1;i>=0;i--)
            topol.push_back(topolt[i]);
        for(int i=0;i<topol.size();i++)
        {
            if(!mark[topol[i]])
            {
                ans++;
                dfs2(topol[i]);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
