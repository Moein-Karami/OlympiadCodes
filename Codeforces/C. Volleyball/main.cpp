///Chefer

#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e3+10;
vector <pii> t[maxn],v[maxn];
int val[maxn];
int n,m,x,y;
void clean()
{
    for(int i=1;i<=n;i++)
        val[i]=1e15;
}
main()
{
    cin>>n>>m>>x>>y;
    int t1,t2,w;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2>>w;
        t[t1].push_back(pii(w,t2));
        t[t2].push_back(pii(w,t1));
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2;
        set <pii> se;
        clean();
        val[i]=0;
        se.insert(pii(0,i));
        for(int j=1;j<=n;j++)
            if(j!=i)
                se.insert(pii(1e15,j));
        for(int j=1;j<=n;j++)
        {
            set<pii>::iterator tmp;
            tmp=se.begin();
            se.erase(*tmp);
            int u=(*tmp).s;
            for(int k=0;k<t[u].size();k++)
            {
                if(val[t[u][k].s]>val[u]+t[u][k].f)
                {
                    se.erase(pii(val[t[u][k].s],t[u][k].s));
                    val[t[u][k].s]=val[u]+t[u][k].f;
                    se.insert(pii(val[t[u][k].s],t[u][k].s));
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(j!=i&&val[j]<=t1)
                v[i].push_back(pii(t2,j));
        }
    }
    ///
    set <pii> se;
    clean();
    val[x]=0;
    se.insert(pii(0,x));
    for(int j=1;j<=n;j++)
        if(j!=x)
            se.insert(pii(1e15,j));
    for(int j=1;j<=n;j++)
    {
        set<pii>::iterator tmp;
        tmp=se.begin();
        se.erase(*tmp);
        int u=(*tmp).s;
        for(int k=0;k<v[u].size();k++)
        {
            if(val[v[u][k].s]>val[u]+v[u][k].f)
            {
                se.erase(pii(val[v[u][k].s],v[u][k].s));
                val[v[u][k].s]=val[u]+v[u][k].f;
                se.insert(pii(val[v[u][k].s],v[u][k].s));
            }
        }
    }
    ///
    if(val[y]==1e15)
        cout<<-1;
    else
        cout<<val[y];
    return 0;
}
