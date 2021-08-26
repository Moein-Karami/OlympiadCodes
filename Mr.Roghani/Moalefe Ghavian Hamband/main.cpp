///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5;
vector <int> edg[maxn],bckedge[maxn];
vector <int> topol;
bool m1[maxn];
bool m2[maxn];
vector <int> ans[maxn];
int cnt;
void dfs(int x)
{
    for(int i=0;i<edg[x].size();i++)
    {
        int u=edg[x][i];
        if(!m1[u])
        {
            m1[u]=1;
            dfs(u);
        }
    }
    topol.push_back(x);
}
void dfs2(int x)
{
    for(int i=0;i<bckedge[x].size();i++)
    {
        int u=bckedge[x][i];
        if(!m2[u])
        {
            ans[cnt].push_back(u);
            m2[u]=1;
            dfs2(u);
        }
    }
}
main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        edg[t1].push_back(t2);
        bckedge[t2].push_back(t1);
    }
    for(int i=1;i<=n;i++)
    {
        if(!m1[i])
        {
            m1[i]=1;
            dfs(1);
        }
    }
    for(int i=topol.size()-1;i>=0;i--)
    {
        if(!m2[topol[i]])
        {
            cnt++;
            ans[cnt].push_back(topol[i]);
            m2[topol[i]]=1;
            dfs2(topol[i]);
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
