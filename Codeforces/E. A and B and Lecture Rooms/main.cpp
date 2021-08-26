///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5;
vector <int> v[maxn];
int h[maxn];
int p[maxn][31];
int cnt[maxn];
void dfs(int x)
{
    cnt[x]++;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!p[u][0])
        {
            h[u]=h[x]+1;
            p[u][0]=x;
            for(int j=1;j<30;j++)
                p[u][j]=p[p[u][j-1]][j-1];
            dfs(u);
            cnt[x]+=cnt[u];
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
            y=p[y][i],ret+=(1<<i);
    }
    if(x==y)
        return ret;
    for(int i=30;i>=0;i--)
    {
        if(p[x][i]!=p[y][i])
        {
            ret+=2*(1<<i);
            x=p[x][i];
            y=p[y][i];
        }
    }
    return ret+2;
}
int LCA(int  x,int y)
{
    if(h[x]>h[y])
        swap(x,y);
    for(int i=30;i>=0;i--)
    {
        if(h[y]-(1<<i)>=h[x])
            y=p[y][i];
    }
    if(x==y)
        return x;
    for(int i=30;i>=0;i--)
    {
        if(p[x][i]!=p[y][i])
        {
            x=p[x][i];
            y=p[y][i];
        }
    }
    return p[x][0];
}
int parent  (int x,int lca)
{
    for(int i=30;i>=0;i--)
    {
        if(h[x]-(1<<i)>h[lca])
            x=p[x][i];
    }
    return x;
}
int after(int x,int y)
{
    for(int i=30;i>=0;i--)
        if((1<<i)<=y)
            x=p[x][i],y-=(1<<i);
    return x;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    p[1][0]=1;
    dfs(1);
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int t1,t2;
        cin>>t1>>t2;
        if(t1==t2)
        {
            cout<<n<<endl;
            continue;
        }
        int pth=path(t1,t2);
        if(pth%2==1)
            cout<<0<<endl;
        else
        {
            int lca=LCA(t1,t2);
            int midpth=path(t1,t2)/2;
            //cerr<<"MIDPATH : "<<midpth<<endl;
            if(h[t1]-h[lca]==midpth)
            {
                int pt1=parent(t1,lca);
                int pt2=parent(t2,lca);
                //cerr<<"TEST : "<<lca<<endl;
                cout<<n-cnt[pt1]-cnt[pt2]<<endl;
            }
            else
            {
                int midv;
                if(h[t1]-h[lca]>=midpth)
                {
                    midv=after(t1,midpth);
                    cout<<cnt[midv]-cnt[parent(t1,midv)]<<endl;
                }
                else
                {
                    midv=after(t2,midpth);
                    //cerr<<"MIDV : "<<midv<<endl;
                    cout<<cnt[midv]-cnt[parent(t2,midv)]<<endl;
                }

            }

        }
    }
    return 0;
}
