///DARK PROGRAMMER



#include <bits/stdc++.h>
int ans;
using namespace std;
const int maxn=1e3;
vector <int> v[maxn][maxn];
vector <int> color[maxn];
bool b[maxn],col[maxn];
int n,m;
void empt()
{
    for(int i=1;i<=n;i++)
        b[i]=0;
}
void empT()
{
    for(int i=1;i<=n;i++)
        col[i]=0;
}
void dfs(int c,int x)
{
    for(int i=0;i<v[c][x].size();i++)
    {
        if(!b[v[c][x][i]])
        {
            b[v[c][x][i]]=1;
            dfs(c,v[c][x][i]);
        }
    }
}
int main()
{
    cin>>n>>m;
    int a,s,d;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>s>>d;
        v[d][s].push_back(a);
        v[d][a].push_back(s);
        color[a].push_back(d);
        color[s].push_back(d);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        ans=0;
        cin>>a>>s;
        empT();
        for(int j=0;j<color[a].size();j++)
        {
            if(!col[color[a][j]])
            {
                empt();
                b[a]=1;
                dfs(color[a][j],a);
                if(b[s])
                    ans++;
                col[color[a][j]]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
