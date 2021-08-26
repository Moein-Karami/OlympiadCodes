///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
const int maxn=2e5,inf =1e12;
typedef pair<int,int > pii;
typedef pair<int ,pii> pip;
vector <pii> v[maxn];
int val[maxn];
main()
{
    int n,m;
    cin>>n>>m;
    int t1,t2,t3;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        if(t1!=t2)
        {
            v[t1].push_back(pii(t2,0));
            v[t2].push_back(pii(t1,1));
        }
    }
    for(int i=2;i<=n;i++)
        val[i]=inf;
    set <pii> se;
    se.insert(pii(0,1));
    set<pii>::iterator x;
    while(se.size())
    {
        x=se.begin();
        se.erase(*x);
        int u=(*x).s;
        for(int i=0;i<v[u].size();i++)
        {
            int t=v[u][i].f;
            int w=v[u][i].s;
            if(val[t]>val[u]+w)
            {
                val[t]=val[u]+w;
                se.insert(pii(val[t],t));
            }
        }
    }
    if(val[n]==inf)
    {
        cout<<-1;
        return 0;
    }
    cout<<val[n];
    return 0;
}
