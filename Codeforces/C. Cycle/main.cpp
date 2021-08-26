///Chefer


#include <bits/stdc++.h>

using namespace std;
vector <int> topolt;
vector <int> topol;
const int maxn=5e3+5;
bool mat[maxn][maxn];
bool b[maxn];
int p[maxn];
int son=0;
int parent=0;
vector <int> cycle;
bool b2[maxn];
int n;
vector<int> v[maxn];
int mark[maxn];
void dfs(int x)
{
    b[x]=1;
    int u;
    for(int i=0;i<v[x].size();i++)
    {
        u=v[x][i];
        if(!p[u])
            p[u]=x;
        if(!b[u])
            dfs(u);
    }
    topolt.push_back(x);
    mark[x]=topolt.size();
}
bool dfs2(int x)
{
    //cerr<<"FUCKING X "<<x<<endl;
    bool c=0;
    if(!b2[x]&&x==son)
        c=1;
    b2[x]=1;
    int u;
    for(int i=0;i<v[x].size();i++)
    {
        u=v[x][i];
        if(!b2[u])
        {
            if(dfs2(u))
            {
                cycle.push_back(u);
                c=1;
            }

        }
    }
    return c;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char c[maxn];
        scanf("%s",c);
        for(int j=1;j<=n;j++)
        {
            mat[i][j]=c[j-1]-'0';
            if(mat[i][j])
                v[i].push_back(j);
        }
    }

    for(int i=1;i<=n;i++)
        if(!b[i])
            dfs(i);
    for(int i=topolt.size()-1;i>=0;i--)
        topol.push_back(topolt[i]);
    int u;
    int l;

    for(int i=0;i<topol.size();i++)
    {
        u=topol[i];
        for(int j=0;j<v[u].size();j++)
        {
            l=v[u][j];
            if(mark[l]>mark[u])
            {
                parent=l;
                son=u;
                j=maxn;
                i=maxn;
            }
        }
    }
    if(!son)
    {
        cout<<-1;
        return 0;
    }
    dfs2(parent);
    cycle.push_back(parent);
    int s;
    int t1,t2,t3;
    while(cycle.size()>3)
    {
        s=cycle.size()-1;
        t1=cycle[s];
        t2=cycle[s-1];
        t3=cycle[s-2];
        cycle.pop_back();
        cycle.pop_back();
        cycle.pop_back();
        if(mat[t3][t1])
        {
            cout<<t1<<" "<<t2<<" "<<t3<<endl;
            return 0;
        }
        else
        {
            cycle.push_back(t3);
            cycle.push_back(t1);
        }
    }
    cout<<cycle[2]<<" "<<cycle[1]<<" "<<cycle[0]<<endl;
    return 0;
}
