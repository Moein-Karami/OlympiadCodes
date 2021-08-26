///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;
typedef pair<int,int> pii;
int val[10010];
int inf=1e15;
vector <int> ans;
main()
{
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int n,m,x,y;
        cin>>n>>m;
        int t1,t2,t3;
        vector <pii> v[n+10];
        for(int i=1;i<=n;i++)
            val[i]=inf;
        for(int i=1;i<=m;i++)
        {
            cin>>t1>>t2>>t3;
            v[t1].push_back(pii(t2,t3));
        }
        cin>>x>>y;
        val[x]=0;
        set <pii> se;
        se.insert(pii(0,x));
        while(se.size())
        {
            set <pii>::iterator tmp,t;
            tmp=se.begin();
            se.erase(*tmp);
            int u=(*tmp).s,w,g;
            for(int i=0;i<v[u].size();i++)
            {
                g=v[u][i].f;
                w=v[u][i].s;
                if(val[g]>val[u]+w)
                {
                    //t=se.find(pii(val[g],g));
                    //if((*t).s)
                      //  se.erase(pii(val[g],g));
                    val[g]=val[u]+w;
                    se.insert(pii(val[g],g));
                }
            }
        }
        if(val[y]>=inf)
        {
            ans.push_back(-1);
            continue ;
        }
        ans.push_back(val[y]);
    }

    for(int i=0;i<q;i++)
    {
        if(ans[i]==-1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<ans[i]<<endl;
    }

    return 0;
}
