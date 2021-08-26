///DAEK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+10;
vector <int> v[maxn];
int h1[maxn],h2[maxn],h[maxn],h3[maxn];
bool b1[maxn],b2[maxn];
bool z[maxn],kharab[maxn];
int maxi,maxi2;
int n,m,d;
int dfs1(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!b1[v[x][i]])
        {
            b1[v[x][i]]=1;
            h1[v[x][i]]=h1[x]+1;
            if(h1[v[x][i]]>=h1[maxi]&&z[v[x][i]])
                maxi=v[x][i];
            dfs1(v[x][i]);
        }
    }
}
int dfs2(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!b2[v[x][i]])
        {
            b2[v[x][i]]=1;
            h2[v[x][i]]=h2[x]+1;
            if(h2[v[x][i]]>=h2[maxi2]&&z[v[x][i]])
                maxi2=v[x][i];
            dfs2(v[x][i]);
        }
    }
}
int dfs(int p,int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p)
        {
            h[v[x][i]]=h[x]+1;
            dfs(x,v[x][i]);
        }
    }
}
int dfs3(int p,int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p)
        {
            h3[v[x][i]]=h3[x]+1;
            dfs3(x,v[x][i]);

        }
    }
}
int main()
{
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        z[a]=1;
    }

    for(int i=1;i<n;i++)
    {
        int a,c;
        cin>>a>>c;
        v[a].push_back(c);
        v[c].push_back(a);
    }
    int x;
    for(int i=1;i<maxn;i++)
    {
        if(z[i])
        {
            x=i;
            break;
        }
    }
    b1[x]=1;
    dfs1(x);
    b2[maxi]=1;
    dfs2(maxi);
    if(m==1)
    {
        maxi=x;
        maxi2=x;
    }
    dfs(maxi,maxi);
    int f=h[maxi2];
    h[maxi2]=0;
    dfs3(maxi2,maxi2);
    h[maxi2]=f;
    h[maxi]=f;
    h3[maxi2]=f;
    h3[maxi]=f;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(h[i]<=d&&h3[i]<=d)
        ans++;
    cout<<ans;
    return 0;
}
