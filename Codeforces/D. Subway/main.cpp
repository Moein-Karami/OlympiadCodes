///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
const int maxn=1e4;
int parent[maxn];
vector <int> v[maxn];
vector <int> cycle;
int ans[maxn];
bool b1[maxn],b[maxn];
int ras;

void dor(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!b1[v[x][i]])
        {
            b1[v[x][i]]=1;
            parent[v[x][i]]=x;
            dor(v[x][i]);
        }
        else if(ras==0&&b1[v[x][i]]&&v[x][i]!=parent[x])
        {
            parent[v[x][i]]=x;
            cycle.push_back(x);
            b[x]=1;
            ras=x;
            return;
        }
    }
}
void dfs(int p,int x)
{
    ans[x]=ans[p]+1;
    for(int i=0;i<v[x].size();i++)
    {
        if(!b[v[x][i]])
        {
            b[v[x][i]]=1;
            dfs(x,v[x][i]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        v[a].push_back(c);
        v[c].push_back(a);
    }
    b1[1]=1;
    parent [1]=1;
    dor(1);
    int tmp=ras;
    ras=parent[ras];
    while(ras!=tmp)
    {
       cycle.push_back(ras);
       ans[ras]=0;
       b[ras]=1;
       ras=parent[ras];
    }
    ans[0]=-1;
    for(int i=0;i<cycle.size();i++)
    {
        dfs(0,cycle[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
