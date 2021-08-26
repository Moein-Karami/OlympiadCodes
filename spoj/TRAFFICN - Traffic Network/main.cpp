///Chefer



#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;
typedef pair<int,int> pii ;
int val1[10010];
int val2[10010];
const int inf=1e15;
main()
{
    //cout.sync_with_stdio(false);
    //cin.sync_with_stdio(false);
    std::ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int n,m,k,x,y;
        cin>>n>>m>>k>>x>>y;
        vector <pii> v1[n+10],v2[n+10];
        int t1,t2,t3;
        for(int i=1;i<=m;i++)
        {
            cin>>t1>>t2>>t3;
            v1[t1].push_back(pii(t2,t3));
            v2[t2].push_back(pii(t1,t3));
        }
        for(int i=1;i<=n;i++)
            val1[i]=inf,val2[i]=inf;
        val1[x]=0;
        val2[y]=0;
        set <pii> se1,se2;
        se1.insert(pii(0,x));
        se2.insert(pii(0,y));
        while(se1.size())
        {
            set<pii>::iterator t,tmp;
            t=se1.begin();
            se1.erase(*t);
            int u=(*t).s,w,g;
            for(int i=0;i<v1[u].size();i++)
            {
                g=v1[u][i].f;
                w=v1[u][i].s;
                if(val1[g]>val1[u]+w)
                {
                    val1[g]=val1[u]+w;
                    se1.insert(pii(val1[g],g));
                }
            }
        }
        while(se2.size())
        {
            set<pii>::iterator t,tmp;
            t=se2.begin();
            se2.erase(*t);
            int u=(*t).s,w,g;
            for(int i=0;i<v2[u].size();i++)
            {
                g=v2[u][i].f;
                w=v2[u][i].s;
                if(val2[g]>val2[u]+w)
                {
                    val2[g]=val2[u]+w;
                    se2.insert(pii(val2[g],g));
                }
            }
        }
        int ans=val1[y];
        for(int  i=1;i<=k;i++)
        {
            cin>>t1>>t2>>t3;
            ans=min(ans,val1[t1]+val2[t2]+t3);
            ans=min(ans,val1[t2]+val2[t1]+t3);
        }

        if(ans==inf)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
