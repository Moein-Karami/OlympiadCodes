///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e4;
vector <pii> v[maxn];
pii p[maxn][30];
int h[maxn];
bool b[maxn];
void clean(int n)
{
    for(int i=0;i<=n+10;i++)
    {
        for(int j=0;j<30;j++)
            p[i][j].f=0,p[i][j].s=0;
        v[i].clear();
        b[i]=0;
    }
}
void dfs(int parent,int x)
{
    int u,w;
    for(int i=0;i<v[x].size();i++)
    {
        u=v[x][i].f;
        w=v[x][i].s;
        if(!b[u])
        {
            b[u]=1;
            h[u]=h[x]+1;
            p[u][0].f=x;
            p[u][0].s=w;
            for(int j=1;j<30;j++)
            {
                p[u][j].f=p[p[u][j-1].f][j-1].f;
                p[u][j].s=p[u][j-1].s+p[p[u][j-1].f][j-1].s;
            }
            dfs(x,u);
        }
    }
}
main()
{
    //ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    int n,t1,t2,t3,ans;
    string s;
    for(int o=1;o<=q;o++)
    {
        cin>>n;
        clean(n);
        for(int i=1;i<n;i++)
        {
            cin>>t1>>t2>>t3;
            v[t1].push_back(pii(t2,t3));
            v[t2].push_back(pii(t1,t2));
        }
        p[1][0].f=1;
        b[1]=1;
        dfs(1,1);
        //for(int i=1;i<=n;i++)
        //{
          //  cerr<<i<<" : "<<endl;
            //for(int j=0;j<=5;j++)
              //  if(p[i][j].f)
                //    cerr<<j<<" "<<p[i][j].f<<endl;
        //}
        cin>>s;
        while(s!="DONE")
        {
            ans=0;
            if(s=="DIST")
            {

                cin>>t1>>t2;
                if(h[t1]>h[t2])
                    swap(t1,t2);
                for(int i=29;i>=0;i--)
                {
                    if(h[t2]-(1<<i)>=h[t1])
                    {
                        ans+=p[t2][i].s;
                        t2=p[t2][i].f;
                    }
                }

                if(t1!=t2)
                {
                    for(int i=29;i>=0;i--)
                    {
                        if(p[t1][i].f!=p[t2][i].f)
                        {
                            ans+=p[t1][i].s+p[t2][i].s;
                            t1=p[t1][i].f;
                            t2=p[t2][i].f;
                        }
                    }
                    ans+=p[t1][0].s+p[t2][0].s;
                }
                cout<<ans<<"\n";
            }
            else
            {
                cin>>t1>>t2>>t3;
                t3--;
                int tmp1=t1,tmp2=t2,lca;
                if(h[t1]>h[t2])
                    swap(t1,t2);
                for(int i=29;i>=0;i--)
                    if(h[t2]-(1<<i)>=h[t1])
                        t2=p[t2][i].f;
                if(t1==t2)
                    lca=t1;
                if(t1!=t2)
                {
                    for(int i=29;i>=0;i--)
                    {
                        if(p[t1][i].f!=p[t2][i].f)
                        {
                            t1=p[t1][i].f;
                            t2=p[t2][i].f;
                        }
                    }
                    lca=p[t1][0].f;
                }
                if(h[tmp1]-t3>=h[lca])
                {
                    int x=h[tmp1]-t3;
                    for(int i=29;i>=0;i--)
                        if(h[tmp1]-(1<<i)>=x)
                            tmp1=p[tmp1][i].f;
                    cout<<tmp1<<"\n";
                }
                else
                {
                    int x=h[lca]-(h[tmp1]-t3);
                    for(int i=29;i>=0;i--)
                        if(h[tmp2]-(1<<i)>=x)
                            tmp2=p[tmp2][i].f;
                    cout<<tmp2<<"\n";
                }
            }
            cin>>s;
        }
    }
    return 0;
}
