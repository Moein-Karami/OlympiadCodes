///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const  int maxn=2e4;
vector <pii> v[maxn];
pii p[maxn][31];
int h[maxn];
void clean()
{
    for(int i=0;i<maxn;i++)
    {
        h[i]=0;
        v[i].clear();
        for(int j=0;j<31;j++)
            p[i][j].f=0,p[i][j].s=0;
    }
}
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i].f;
        int w=v[x][i].s;
        if(!p[u][0].f)
        {
            h[u]=h[x]+1;
            p[u][0].f=x;
            p[u][0].s=w;
            for(int j=1;j<30;j++)
            {
                p[u][j].f=p[p[u][j-1].f][j-1].f;
                p[u][j].s=p[u][j-1].s+p[p[u][j-1].f][j-1].s;
            }
            dfs(u);
        }
    }

}
int path(int x,int y)
{
    int ret=0;
    if(h[x]>h[y])
        swap(x,y);
    for(int i=30;i>=0;i--)
    {
        if(h[y]-(1<<i)>=h[x])
        {
            ret+=p[y][i].s;
            y=p[y][i].f;
        }
    }
    if(x==y)
        return ret;
    for(int i=30;i>=0;i--)
    {
        if(p[y][i].f!=p[x][i].f)
        {
            ret+=p[y][i].s+p[x][i].s;
            y=p[y][i].f;
            x=p[x][i].f;
        }
    }
    return ret+p[x][0].s+p[y][0].s;
}
int LCA(int x,int y)
{
    if(h[x]>h[y])
        swap(x,y);
    for(int i=30;i>=0;i--)
        if(h[y]-(1<<i)>=h[x])
            y=p[y][i].f;
    if(x==y)
        return x;
    for(int i=30;i>=0;i--)
    {
        if(p[y][i].f!=p[x][i].f)
        {
            y=p[y][i].f;
            x=p[x][i].f;
        }
    }
    return p[x][0].f;
}
int after(int x,int y)
{
    for(int i=30;i>=0;i--)
    {
        if((1<<i)<=y)
        {
            x=p[x][i].f;
            y-=(1<<i);
        }
    }
    return x;
}
main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int n;
        cin>>n;
        clean();
        int t1,t2,t3;
        for(int i=1;i<n;i++)
        {
            cin>>t1>>t2>>t3;
            v[t1].push_back(pii(t2,t3));
            v[t2].push_back(pii(t1,t3));
        }
        p[1][0].f=1;
        dfs(1);
        string s;
        cin>>s;
        while(s!="DONE")
        {
            if(s=="DIST")
            {
                cin>>t1>>t2;
                cout<<path(t1,t2)<<endl;
            }
            else
            {
                cin>>t1>>t2>>t3;
                t3--;
                int lca=LCA(t1,t2);
                if(t3<=h[t1]-h[lca])
                    cout<<after(t1,t3)<<endl;
                else
                {
                    t3-=(h[t1]-h[lca]);
                    t3=(h[t2]-h[lca]-t3);
                    cout<<after(t2,t3)<<endl;
                }
            }
            cin>>s;
        }
    }
    return 0;
}
