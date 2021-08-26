///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e3;

vector <int> v[maxn];
bool bson[maxn];
bool b[maxn];
int p[maxn][11];
int h[maxn];
void clean(int n)
{
    for(int i=0;i<n+10;i++)
    {
        bson[i]=0;
        b[i]=0;
        for(int j=0;j<11;j++)
            p[i][j]=0;
        v[i].clear();
        h[i]=0;
    }
}
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!b[u])
        {
            h[u]=h[x]+1;
            b[u]=1;
            p[u][0]=x;
            for(int j=1;j<=10;j++)
                p[u][j]=p[p[u][j-1]][j-1];
            dfs(u);
        }
    }
}
main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;o++)
    {
        int n;
        cin>>n;
        clean(n);
        int m,tmp;
        for(int j=1;j<=n;j++)
        {
            cin>>m;
            for(int k=1;k<=m;k++)
            {
                cin>>tmp;
                v[j].push_back(tmp);
                v[tmp].push_back(j);
                bson[tmp]=1;
            }
        }
        int root;
        for(int i=1;i<=n;i++)
            if(!bson[i])
                root=i;
        b[root]=1;
        dfs(root);
        int q;
        cin>>q;
        int t1,t2;
        cout<<"Case "<<o<<":"<<endl;
        for(int e=1;e<=q;e++)
        {
            cin>>t1>>t2;
            if(h[t1]>h[t2])
                swap(t1,t2);
            for(int i=10;i>=0;i--)
            {
                if(h[t2]-(1<<i)>=h[t1])
                    t2=p[t2][i];
            }
            if(t1==t2)
            {
                cout<<t1<<"\n";
                continue;
            }
            for(int i=10;i>=0;i--)
            {
                if(p[t1][i]!=p[t2][i])
                {
                    t1=p[t1][i];
                    t2=p[t2][i];
                }
            }
            cout<<p[t1][0]<<"\n";
        }
    }
    return 0;
}
